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


#include "Cpu.hh"


class CpuPrivate {
public:
	CpuComponents m_cpu_comps;
};

Cpu::Cpu (QObject *parent) : QThread (parent) {
	p = new CpuPrivate ();

	m_cpu_state = CPU_STATE_PAUSE;
	m_thread_delay = 5000;
}

Cpu::~Cpu () {
	delete p;
}

ExecutionUnit&
Cpu::getExecutionUnit () {
	return p->m_cpu_comps.getExecutionUnit ();
}

BusInterfaceUnit&
Cpu::getBusInterfaceUnit () {
	return p->m_cpu_comps.getBusInterfaceUnit ();
}

Memory&
Cpu::getMemory () {
	return p->m_cpu_comps.getMemory ();
}

ArithmeticLogicUnit&
Cpu::getArithmeticLogicUnit () {
	return p->m_cpu_comps.getArithmeticLogicUnit ();
}

InstructionDecoder&
Cpu::getInstructionDecoder () {
	return p->m_cpu_comps.getInstructionDecoder ();
}

Loader&
Cpu::getLoader () {
	return p->m_cpu_comps.getLoader ();
}

//override
void
Cpu::run () {
	m_thread_run = true;

	while (m_thread_run) {
		switch (m_cpu_state) {
		case CPU_STATE_RUN:
			//std::cout << "cpu_state_run" << std::endl;
			getInstructionDecoder ().nextInstruction ();
			QThread::usleep (m_thread_delay);
			break;
		case CPU_STATE_SINGLE_STEP:
			//std::cout << "cpu_state_single_step" << std::endl;
			getInstructionDecoder ().nextInstruction ();
			m_mutex.lock ();
				m_cpu_state = CPU_STATE_PAUSE;
			m_mutex.unlock ();
			break;
		case CPU_STATE_PAUSE:
			//std::cout << "cpu_state_pause" << std::endl;
			QThread::usleep (100000);
			//QThread::yieldCurrentThread ();
			break;
		}

		if (p->m_cpu_comps.getHalt ()) {
			m_mutex.lock ();
				m_cpu_state = CPU_STATE_PAUSE;
			m_mutex.unlock ();
			p->m_cpu_comps.setHalt (false);
		}
	}
}

void
Cpu::startCpu () {
	if (!isRunning ()) {
		return;
	}

	m_mutex.lock ();
	m_cpu_state = CPU_STATE_RUN;
	m_mutex.unlock ();
}

void
Cpu::pauseCpu () {
	m_mutex.lock ();
	m_cpu_state = CPU_STATE_PAUSE;
	m_mutex.unlock ();
}

void
Cpu::resetCpu () {
	pauseCpu ();
}

void
Cpu::singleStepCpu () {
	m_mutex.lock ();
	m_cpu_state = CPU_STATE_SINGLE_STEP;
	m_mutex.unlock ();
}

void
Cpu::shutdownCpu () {
	m_thread_run = false;
	wait ();
}

void
Cpu::loadFile (QString file_name) {
	pauseCpu ();
	getLoader ().loadFile (file_name.toStdString ());
	start ();
}

void
Cpu::setSpeed (int i) {
	m_thread_delay = i;
}

