#include "BusInterfaceUnit.hh"

void
BusInterfaceUnit::initialize () {
	//FIXME
}

void
BusInterfaceUnit::connect_to (Memory &mem) {
	m_memory = &mem;

	//FIXME - connect to signals
}

Number<unsigned short>&
BusInterfaceUnit::get_sreg_cs () {
	return m_sreg_cs;
}

void
BusInterfaceUnit::set_sreg_cs (unsigned short val) {
	m_sreg_cs = val;
}

Number<unsigned short>&
BusInterfaceUnit::get_sreg_ds () {
	return m_sreg_ds;
}

void
BusInterfaceUnit::set_sreg_ds (unsigned short val) {
	m_sreg_ds = val;
}

Number<unsigned short>&
BusInterfaceUnit::get_sreg_es () {
	return m_sreg_es;
}

void
BusInterfaceUnit::set_sreg_es (unsigned short val) {
	m_sreg_es = val;
}

Number<unsigned short>&
BusInterfaceUnit::get_sreg_ss () {
	return m_sreg_ss;
}

void
BusInterfaceUnit::set_sreg_ss (unsigned short val) {
	m_sreg_ss = val;
}

Number<unsigned short>&
BusInterfaceUnit::get_reg_ip () {
	return m_reg_ip;
}

void
BusInterfaceUnit::set_reg_ip (unsigned short val) {
	m_reg_ip = val;
}

void
BusInterfaceUnit::set_seg_override (unsigned short val) {
	m_seg_override = val;
}

MemoryAddress*
BusInterfaceUnit::get_memory_address (unsigned short seg, unsigned short offset) {
	if (m_seg_override != (unsigned short)-1) {
		seg = m_seg_override;
		m_seg_override = (unsigned short)-1;
	}

	return new MemoryAddress (m_memory, seg, offset);
}

