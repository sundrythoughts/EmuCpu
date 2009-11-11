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


#include "BusInterfaceUnit.hh"
#include "CpuComponents.hh"

class BusInterfaceUnitPrivate {
public:
	CpuComponents *m_cpu;
};

BusInterfaceUnit::BusInterfaceUnit () : m_ip (0), m_seg_override (-1),
                                        m_reg_ip (m_ip), m_memory (0)
{
	p = new BusInterfaceUnitPrivate ();

	m_seg_regs[Jaf::SREG_CS].reinitialize (m_sregs[Jaf::SREG_CS]);
	m_seg_regs[Jaf::SREG_DS].reinitialize (m_sregs[Jaf::SREG_DS]);
	m_seg_regs[Jaf::SREG_ES].reinitialize (m_sregs[Jaf::SREG_ES]);
	m_seg_regs[Jaf::SREG_SS].reinitialize (m_sregs[Jaf::SREG_SS]);
}

BusInterfaceUnit::~BusInterfaceUnit () {
	delete p;
}

void
BusInterfaceUnit::reset () {
	m_ip = 0;
	m_seg_override = -1;
}

void
BusInterfaceUnit::initialize () {
	//FIXME
}

void
BusInterfaceUnit::connectTo (CpuComponents &cpu) {
	p->m_cpu = &cpu;
	m_memory = &cpu.getMemory ();

	//FIXME - connect to signals
}

Register<unsigned short>&
BusInterfaceUnit::getSegReg (size_t index) {
	return m_seg_regs[index];
}

void
BusInterfaceUnit::setSegReg (size_t index, unsigned short val) {
	m_seg_regs[index] = val;
}

Register<unsigned short>&
BusInterfaceUnit::getSegRegCS () {
	return m_seg_regs[Jaf::SREG_CS];
}

void
BusInterfaceUnit::setSegRegCS (unsigned short val) {
	m_seg_regs[Jaf::SREG_CS] = val;
}

Register<unsigned short>&
BusInterfaceUnit::getSegRegDS () {
	return m_seg_regs[Jaf::SREG_DS];
}

void
BusInterfaceUnit::setSegRegDS (unsigned short val) {
	m_seg_regs[Jaf::SREG_DS] = val;
}

Register<unsigned short>&
BusInterfaceUnit::getSegRegES () {
	return m_seg_regs[Jaf::SREG_ES];
}

void
BusInterfaceUnit::setSegRegES (unsigned short val) {
	m_seg_regs[Jaf::SREG_ES] = val;
}

Register<unsigned short>&
BusInterfaceUnit::getSegRegSS () {
	return m_seg_regs[Jaf::SREG_SS];
}

void
BusInterfaceUnit::setSegRegSS (unsigned short val) {
	m_seg_regs[Jaf::SREG_SS] = val;
}

Register<unsigned short>&
BusInterfaceUnit::getRegIP () {
	return m_reg_ip;
}

void
BusInterfaceUnit::setRegIP (unsigned short val) {
	m_reg_ip = val;
}

void
BusInterfaceUnit::setSegOverride (unsigned short val) {
	m_seg_override = val;
}

