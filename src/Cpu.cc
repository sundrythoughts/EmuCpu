#include "Cpu.hh"

ExecutionUnit&
Cpu::getExecutionUnit () {
	return m_eunit;
}

BusInterfaceUnit&
Cpu::getBusInterfaceUnit () {
	return m_biu;
}

Memory&
Cpu::getMemory () {
	return m_mem;
}

//override
void
Cpu::run () {
	m_thread_run = true;

	while (m_thread_run) {
		switch (m_cpu_state) {
		case CPU_STATE_RUN:
			//std::cout << "cpu_state_run" << std::endl;
			m_decoder.nextInstruction ();
			break;
		case CPU_STATE_SINGLE_STEP:
			//std::cout << "cpu_state_single_step" << std::endl;
			m_decoder.nextInstruction ();
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
		std::cout << "";
	}
}

void
Cpu::startCpu () {
	//std::cout << "startCpu ()" << std::endl;
	m_mutex.lock ();
	m_cpu_state = CPU_STATE_RUN;
	m_mutex.unlock ();
}

void
Cpu::pauseCpu () {
	//std::cout << "pauseCpu ()" << std::endl;
	m_mutex.lock ();
	m_cpu_state = CPU_STATE_PAUSE;
	m_mutex.unlock ();
}

void
Cpu::resetCpu () {
	pauseCpu ();
	//std::cout << "resetCpu ()" << std::endl;
}

void
Cpu::singleStepCpu () {
	//std::cout << "singleStepCpu ()" << std::endl;
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
	m_loader.loadFile (file_name.toStdString ());
	//m_mem.write<unsigned int> (14, 0x01020304);
}
