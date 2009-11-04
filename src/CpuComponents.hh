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


#ifndef JAF__CPU_COMPONENTS_HH
#define JAF__CPU_COMPONENTS_HH

#include "ExecutionUnit.hh"
#include "ArithmeticLogicUnit.hh"
#include "BusInterfaceUnit.hh"
#include "Memory.hh"
#include "InstructionDecoder.hh"
#include "Loader.hh"

class InstructionDecoder;
class ExecutionUnit;
class BusInterfaceUnit;
class ArithmeticLogicUnit;
class BusInterfaceUnit;
class Memory;
class Loader;

class CpuComponentsPrivate;

class CpuComponents {
	CpuComponentsPrivate *p;

public:
	/** */
	CpuComponents ();

	/** */
	~CpuComponents ();

	/** */
	ExecutionUnit& getExecutionUnit ();

	/** */
	BusInterfaceUnit& getBusInterfaceUnit ();

	/** */
	Memory& getMemory ();

	/** */
	ArithmeticLogicUnit& getArithmeticLogicUnit ();

	/** */
	InstructionDecoder& getInstructionDecoder ();

	/** */
	Loader& getLoader ();

	/** */
	bool getHalt ();

	/** */
	void setHalt (bool b);

}; //end class CpuComponents

#endif //JAF__CPU_COMPONENTS_HH
