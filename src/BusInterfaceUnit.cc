/*
 * emucpu -- Emulates processors
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

Register<quint16>&
BusInterfaceUnit::getSegReg (size_t index) {
	return m_seg_regs[index];
}

void
BusInterfaceUnit::setSegReg (size_t index, quint16 val) {
	m_seg_regs[index] = val;
}

Register<quint16>&
BusInterfaceUnit::getSegRegCS () {
	return m_seg_regs[Jaf::SREG_CS];
}

void
BusInterfaceUnit::setSegRegCS (quint16 val) {
	m_seg_regs[Jaf::SREG_CS] = val;
}

Register<quint16>&
BusInterfaceUnit::getSegRegDS () {
	return m_seg_regs[Jaf::SREG_DS];
}

void
BusInterfaceUnit::setSegRegDS (quint16 val) {
	m_seg_regs[Jaf::SREG_DS] = val;
}

Register<quint16>&
BusInterfaceUnit::getSegRegES () {
	return m_seg_regs[Jaf::SREG_ES];
}

void
BusInterfaceUnit::setSegRegES (quint16 val) {
	m_seg_regs[Jaf::SREG_ES] = val;
}

Register<quint16>&
BusInterfaceUnit::getSegRegSS () {
	return m_seg_regs[Jaf::SREG_SS];
}

void
BusInterfaceUnit::setSegRegSS (quint16 val) {
	m_seg_regs[Jaf::SREG_SS] = val;
}

Register<quint16>&
BusInterfaceUnit::getRegIP () {
	return m_reg_ip;
}

void
BusInterfaceUnit::setRegIP (quint16 val) {
	m_reg_ip = val;
}

void
BusInterfaceUnit::setSegOverride (quint16 val) {
	m_seg_override = val;
}

