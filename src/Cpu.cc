#include "Cpu.hh"

class CpuPrivate {
public:
	Memory m_mem;
	ExecutionUnit m_eunit;
	ArithmeticLogicUnit m_alu;
	BusInterfaceUnit m_biu;
	InstructionDecoder m_decoder;
	Loader m_loader;
};

Cpu::Cpu (QObject *parent) : QThread (parent) {
	p = new CpuPrivate ();

	m_cpu_state = CPU_STATE_PAUSE;

	p->m_eunit.connectTo (*this);
	p->m_alu.connectTo (*this);
	p->m_decoder.connectTo (*this);
	p->m_loader.connectTo (*this);
	p->m_biu.connectTo (*this);
}

Cpu::~Cpu () {
	delete p;
}

ExecutionUnit&
Cpu::getExecutionUnit () {
	return p->m_eunit;
}

BusInterfaceUnit&
Cpu::getBusInterfaceUnit () {
	return p->m_biu;
}

Memory&
Cpu::getMemory () {
	return p->m_mem;
}

ArithmeticLogicUnit&
Cpu::getArithmeticLogicUnit () {
	return p->m_alu;
}

//override
void
Cpu::run () {
	m_thread_run = true;

	while (m_thread_run) {
		switch (m_cpu_state) {
		case CPU_STATE_RUN:
			//std::cout << "cpu_state_run" << std::endl;
			p->m_decoder.nextInstruction ();
			break;
		case CPU_STATE_SINGLE_STEP:
			//std::cout << "cpu_state_single_step" << std::endl;
			p->m_decoder.nextInstruction ();
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
	p->m_loader.loadFile (file_name.toStdString ());
	//m_mem.write<unsigned int> (14, 0x01020304);
}
