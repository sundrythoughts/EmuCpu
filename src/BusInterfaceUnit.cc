#include "BusInterfaceUnit.hh"

void
BusInterfaceUnit::initialize () {
	//FIXME
}

void
BusInterfaceUnit::connectTo (Memory &mem) {
	m_memory = &mem;

	//FIXME - connect to signals
}

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

