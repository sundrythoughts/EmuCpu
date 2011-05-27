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


#include "Cpu.hh"
#include "Paths.hh"

#include <QtGlobal>

class CpuPrivate {
public:
	CpuComponents m_cpu_comps;

	QMutex m_mutex;
	bool m_thread_run;
	quint64 m_thread_delay;
};

Cpu::Cpu (QObject *parent) : QThread (parent) {
	p = new CpuPrivate ();

	m_cpu_state = CPU_STATE_PAUSE;
	p->m_thread_delay = 5000;
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

Instruction&
Cpu::getInstruction () {
	return p->m_cpu_comps.getInstruction ();
}

Loader&
Cpu::getLoader () {
	return p->m_cpu_comps.getLoader ();
}

/** Get a reference to the IOPorts. */
IOPorts&
Cpu::getIOPorts () {
	return p->m_cpu_comps.getIOPorts ();
}

//override
void
Cpu::run () {
	p->m_thread_run = true;

	while (p->m_thread_run) {
		switch (m_cpu_state) {
		case CPU_STATE_RUN:
			getInstructionDecoder ().nextInstruction ();
			QThread::usleep (p->m_thread_delay);
			break;
		case CPU_STATE_SINGLE_STEP:
			getInstructionDecoder ().nextInstruction ();
			p->m_mutex.lock ();
				m_cpu_state = CPU_STATE_PAUSE;
			p->m_mutex.unlock ();
			break;
		case CPU_STATE_PAUSE:
			QThread::usleep (100000);
			break;
		}

		if (p->m_cpu_comps.getHalt ()) {
			p->m_mutex.lock ();
				m_cpu_state = CPU_STATE_PAUSE;
			p->m_mutex.unlock ();
			p->m_cpu_comps.setHalt (false);
		}
	}
}

void
Cpu::startCpu () {
	if (!isRunning ()) {
		return;
	}

	p->m_mutex.lock ();
		m_cpu_state = CPU_STATE_RUN;
	p->m_mutex.unlock ();
}

void
Cpu::pauseCpu () {
	p->m_mutex.lock ();
		m_cpu_state = CPU_STATE_PAUSE;
	p->m_mutex.unlock ();

	p->m_cpu_comps.setHalt (true);
}

void
Cpu::resetCpu () {
	pauseCpu ();
	p->m_cpu_comps.reset ();
}

void
Cpu::singleStepCpu () {
	p->m_mutex.lock ();
		m_cpu_state = CPU_STATE_SINGLE_STEP;
	p->m_mutex.unlock ();
}

void
Cpu::shutdownCpu () {
	p->m_thread_run = false;
	pauseCpu ();
	wait ();
}

void
Cpu::loadFile (QString file_name, bool load_sim86os) {
	pauseCpu ();
	if (load_sim86os) {
		getLoader ().loadFile (PATH_EMUCPU_SHARE "/EmuCpuOS.obj");
	}
	getLoader ().loadFile (file_name.toStdString ());
	QFileInfo file_info (file_name);
	p->m_cpu_comps.setTestID (file_info.fileName ().toStdString ());
	start ();
}

void
Cpu::setSpeed (int i) {
	p->m_thread_delay = i;
}

