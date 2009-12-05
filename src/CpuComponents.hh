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
@file CpuComponents.hh
@brief Packages together all of the parts of the cpu like the EU, BIU, etc.
*/

#ifndef JAF__CPU_COMPONENTS_HH
#define JAF__CPU_COMPONENTS_HH

#include "ExecutionUnit.hh"
#include "ArithmeticLogicUnit.hh"
#include "BusInterfaceUnit.hh"
#include "Memory.hh"
#include "InstructionDecoder.hh"
#include "Instruction.hh"
#include "Loader.hh"
#include "IOPorts.hh"
#include "ToneGenerator.hh"
#include "DatabaseTester.hh"

class Instruction;
class InstructionDecoder;
class ExecutionUnit;
class BusInterfaceUnit;
class ArithmeticLogicUnit;
class BusInterfaceUnit;
class Memory;
class Loader;
class IOPorts;
class ToneGenerator;
class DatabaseTester;

class CpuComponentsPrivate;

/**
@class CpuComponents
@brief Packages together all of the parts of the cpu like the EU, BIU, etc.
*/
class CpuComponents {
	CpuComponentsPrivate *p;

public:
	/** */
	CpuComponents ();

	/** */
	~CpuComponents ();

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

	/** @brief Get a reference to the ToneGenerator. */
	ToneGenerator& getToneGenerator ();

	/** @brief Get a reference to the DatabaseTester. */
	DatabaseTester& getDatabaseTester ();

	/** @brief Set the name of the current executable. */
	void setTestID (const std::string &t);

	/** @brief Get the name of the current executable. */
	const std::string& getTestID () const;

	/** @brief Get the instruction counter. */
	int getInstCounter () const;

	/** @brief Increment the instruction counter. */
	void incInstCounter ();

	/** @brief Reset the instruction counter. */
	void resetInstCounter ();

	/** @brief Get whether the Cpu is halted or not. */
	bool getHalt ();

	/**
	@brief Set the Cpu to a halted or unhalted state.
	@param b Halt Cpu if true, unhalt Cpu if false.
	*/
	void setHalt (bool b);

	/** @brief FIXME */
	void reset ();

}; //end class CpuComponents

#endif //JAF__CPU_COMPONENTS_HH

