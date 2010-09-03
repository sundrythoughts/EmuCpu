/*
 * sim8086 -- Emulates an Intel 8086 processor
 * Copyright (C) 2009  Joseph Freeman (jfree143dev AT gmail DOT com)
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


/**
@file Cpu.hh
@brief Manage a thread that holds all the components of a Cpu.
*/

#ifndef JAF__CPU_HH
#define JAF__CPU_HH

#include "CpuComponents.hh"

#include <iostream>

#include <QtCore>
#include <QThread>
#include <QMutex>

class CpuPrivate;

/**
@class Cpu
@brief Manage a thread that holds all the components of a Cpu.
*/
class Cpu : public QThread {
	Q_OBJECT

	CpuPrivate *p;

	enum CpuStateEnum {
		CPU_STATE_RUN,
		CPU_STATE_SINGLE_STEP,
		CPU_STATE_PAUSE
	};

	CpuStateEnum m_cpu_state;

public:
	/** */
	Cpu (QObject *parent = 0);

	/** */
	~Cpu ();

	/** @brief Get a reference to the ExecutionUnit. */
	ExecutionUnit& getExecutionUnit ();

	/** @brief Get a reference to the BusInterfaceUnit. */
	BusInterfaceUnit& getBusInterfaceUnit ();

	/** @brief Get a reference to the Memory. */
	Memory& getMemory ();

	/** @brief Get a reference to the ArithmeticLogicUnit. */
	ArithmeticLogicUnit& getArithmeticLogicUnit ();

	/** @brief Get a reference to the InstructionDecoder. */
	InstructionDecoder& getInstructionDecoder ();

	/** @brief Get a reference to the Instruction. */
	Instruction& getInstruction ();

	/** @brief Get a reference to the Loader. */
	Loader& getLoader ();

	/** @brief Get a reference to the IOPorts. */
	IOPorts& getIOPorts ();

protected:
	//virtual override
	/** @brief Run the Cpu thread. */
	virtual void run ();

public Q_SLOTS:
	/** @brief Run the Cpu. */
	void startCpu ();

	/** @brief Pause the Cpu. */
	void pauseCpu ();

	/** @brief Reset the Cpu. */
	void resetCpu ();

	/** @brief Single-step the Cpu. */
	void singleStepCpu ();

	/** @brief Shutdown the Cpu. */
	void shutdownCpu ();

	/** @brief Load a new file to execute. */
	void loadFile (QString file_name, bool load_sim86os);

	/** @brief Change the delay between execution of instructions. */
	void setSpeed (int);

}; //end class Cpu

#endif //JAF__CPU_HH

