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
@file BusInterfaceUnit.hh
@brief Manages the segment registers, the instruction pointer, and memory access.
*/

#ifndef JAF__BUS_INTERFACE_UNIT_HH
#define JAF__BUS_INTERFACE_UNIT_HH

#include "Defines.hh"
#include "Memory.hh"
#include "Register.hh"
#include "MemoryAddress.hh"
#include <vector>
#include <iostream>

class CpuComponents;
class BusInterfaceUnitPrivate;

/**
@class BusInterfaceUnit
@brief Manages the segment registers, the instruction pointer, and memory access.
*/
class BusInterfaceUnit {
	BusInterfaceUnitPrivate *p;

	unsigned short m_sregs[Jaf::SREG_COUNT];
	Register<unsigned short> m_seg_regs[Jaf::SREG_COUNT];

	unsigned short m_ip;
	unsigned short m_seg_override;

	Register<unsigned short> m_reg_ip;

	Memory *m_memory;

public:
	/** */
	BusInterfaceUnit ();

	/** */
	BusInterfaceUnit (const BusInterfaceUnit &src);

	/** */
	~BusInterfaceUnit ();

	/** Reverts to original state. */
	void reset ();

	/** FIXME */
	void initialize ();

	/** Create a connection to the CpuComponents. */
	void connectTo (CpuComponents &cpu);

	/**
	@brief Get reference to a segment register.
	@param index Index of a segment register (possible values are the same as Intel's).
	*/
	Register<unsigned short>& getSegReg (size_t index);

	/**
	@brief Set a segment register value.
	@param index Index of a segment register (possible values are the same as Intel's).
	@param val Value to use.
	*/
	void setSegReg (size_t index, unsigned short val);

	/** Get the CS segment register. */
	Register<unsigned short>& getSegRegCS ();

	/** Set the CS segment register. */
	void setSegRegCS (unsigned short val);

	/** Get the DS segment register. */
	Register<unsigned short>& getSegRegDS ();

	/** Set the DS segment register. */
	void setSegRegDS (unsigned short val);

	/** Get the ES segment register. */
	Register<unsigned short>& getSegRegES ();

	/** Set the ES segment register. */
	void setSegRegES (unsigned short val);

	/** Get the SS segment register. */
	Register<unsigned short>& getSegRegSS ();

	/** Set the SS segment register. */
	void setSegRegSS (unsigned short val);

	/** Get the IP register. */
	Register<unsigned short>& getRegIP ();

	/** Set the IP register. */
	void setRegIP (unsigned short val);

	/** Set the segment override value. */
	void setSegOverride (unsigned short val);

	/**
	@brief Get a copy of data in memory.
	@param seg Segment of memory location.
	@param offset Offset of memory location.
	*/
	template<typename T>
	T getMemoryData (unsigned short seg, unsigned offset);

	/**
	@brief Get a MemoryAddress pointer to a memory location.
	@param mem_addr Reference in which to store the pointer.
	@param seg Segment of memory location.
	@param offset Offset of memory location.
	@param override_the_override If true, then use seg for the segment value even if the instruction has a segment override.
	*/
	template<typename T>
	void getMemoryAddress (MemoryAddress<T> * &mem_addr, unsigned short seg, unsigned short offset, bool override_the_override = false);

	/**
	@brief Get a MemoryAddress pointer to a memory location.
	@param seg Segment of memory location.
	@param offset Offset of memory location.
	@param override_the_override If true, then use seg for the segment value even if the instruction has a segment override.
	@return MemoryAddress pointer to memory location.
	*/
	template<typename T>
	MemoryAddress<T>*
	getMemoryAddress (unsigned short seg, unsigned short offset, bool override_the_override = false);

	/** Read sizeof(T) bytes starting at IP and then increment IP sizeof(T) bytes. */
	template<typename T>
	T getInstructionBytes ();

}; //end class BusInterfaceUnit

template<typename T>
T
BusInterfaceUnit::getMemoryData (unsigned short seg, unsigned offset) {
	size_t addr = (seg << 4) + offset;
	T val;
	m_memory->read (addr, val);
	return val;
}

template<typename T>
void
BusInterfaceUnit::getMemoryAddress (MemoryAddress<T> * &mem_addr, unsigned short seg, unsigned short offset, bool override_the_override) {
	if (!override_the_override && m_seg_override != (unsigned short)-1) {
		seg = m_seg_override;
		m_seg_override = (unsigned short)-1;
	}

	mem_addr = new MemoryAddress<T> (m_memory, seg, offset);
}

template<typename T>
MemoryAddress<T>*
BusInterfaceUnit::getMemoryAddress (unsigned short seg, unsigned short offset, bool override_the_override) {
	if (!override_the_override && m_seg_override != (unsigned short)-1) {
		seg = m_seg_override;
		m_seg_override = (unsigned short)-1;
	}

	return new MemoryAddress<T> (m_memory, seg, offset);
}

template<typename T>
T
BusInterfaceUnit::getInstructionBytes () {
	size_t m_phys_addr = m_seg_regs[Jaf::SREG_CS] << 4;
	m_phys_addr += m_reg_ip;
	T val;
	m_memory->read (m_phys_addr, val);

	m_reg_ip += sizeof(T);

	return val;
}

#endif //JAF__BUS_INTERFACE_UNIT_HH

