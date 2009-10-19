#include "BusInterfaceUnit.hh"
#include "CpuComponents.hh"

class BusInterfaceUnitPrivate {
public:
	CpuComponents *m_cpu;
};

BusInterfaceUnit::BusInterfaceUnit () : m_cs (0), m_ds (0), m_es (0), m_ss (0), m_ip (0), m_seg_override (-1),
                                        m_sreg_cs (m_cs), m_sreg_ds (m_ds),
                                        m_sreg_es (m_es), m_sreg_ss (m_ss),
                                        m_reg_ip (m_ip), m_memory (0)
{
	p = new BusInterfaceUnitPrivate ();
}

BusInterfaceUnit::~BusInterfaceUnit () {
	delete p;
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

//Register<unsigned short>&
//BusInterfaceUnit::getSegReg (size_t index) {
//	return 
//}

//void
//BusInterfaceUnit::setSegReg (size_t index, unsigned short val) {
//}

Register<unsigned short>&
BusInterfaceUnit::getSegRegCS () {
	return m_sreg_cs;
}

void
BusInterfaceUnit::setSegRegCS (unsigned short val) {
	m_sreg_cs = val;
}

Register<unsigned short>&
BusInterfaceUnit::getSegRegDS () {
	return m_sreg_ds;
}

void
BusInterfaceUnit::setSegRegDS (unsigned short val) {
	m_sreg_ds = val;
}

Register<unsigned short>&
BusInterfaceUnit::getSegRegES () {
	return m_sreg_es;
}

void
BusInterfaceUnit::setSegRegES (unsigned short val) {
	m_sreg_es = val;
}

Register<unsigned short>&
BusInterfaceUnit::getSegRegSS () {
	return m_sreg_ss;
}

void
BusInterfaceUnit::setSegRegSS (unsigned short val) {
	m_sreg_ss = val;
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

