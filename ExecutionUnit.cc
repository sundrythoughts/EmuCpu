#include "ExecutionUnit.hh"
#include "Utility.hh"

void
ExecutionUnit::connect_to (BusInterfaceUnit &biu) {
	m_biu = &biu;

	//FIXME - connect to signals
}

BusInterfaceUnit&
ExecutionUnit::get_bus_interface_unit () {
	return *m_biu;
}

Number<unsigned short>&
ExecutionUnit::get_reg_ax () {
	return m_regs16[REG_AX];
}

void
ExecutionUnit::set_reg_ax (unsigned short val) {
	m_regs16[REG_AX] = val;
}

Number<unsigned char>&
ExecutionUnit::get_reg_ah () {
	return m_regs8[REG_AH];
}

void
ExecutionUnit::set_reg_ah (unsigned char val) {
	m_regs8[REG_AH] = val;
}

Number<unsigned char>&
ExecutionUnit::get_reg_al () {
	return m_regs8[REG_AL];
}

void
ExecutionUnit::set_reg_al (unsigned char val) {
	m_regs8[REG_AL] = val;
}

Number<unsigned short>&
ExecutionUnit::get_reg_bx () {
	return m_regs16[REG_BX];
}

void
ExecutionUnit::set_reg_bx (unsigned short val) {
	m_regs16[REG_BX] = val;
}

Number<unsigned char>&
ExecutionUnit::get_reg_bh () {
	return m_regs8[REG_BH];
}

void
ExecutionUnit::set_reg_bh (unsigned char val) {
	m_regs8[REG_BH] = val;
}

Number<unsigned char>&
ExecutionUnit::get_reg_bl () {
	return m_regs8[REG_BL];
}

void
ExecutionUnit::set_reg_bl (unsigned char val) {
	m_regs8[REG_BL] = val;
}

Number<unsigned short>&
ExecutionUnit::get_reg_cx () {
	return m_regs16[REG_CX];
}

void
ExecutionUnit::set_reg_cx (unsigned short val) {
	m_regs16[REG_CX] = val;
}

Number<unsigned char>&
ExecutionUnit::get_reg_ch () {
	return m_regs8[REG_CH];
}

void
ExecutionUnit::set_reg_ch (unsigned char val) {
	m_regs8[REG_CH] = val;
}

Number<unsigned char>&
ExecutionUnit::get_reg_cl () {
	return m_regs8[REG_CL];
}

void
ExecutionUnit::set_reg_cl (unsigned char val) {
	m_regs8[REG_CL] = val;
}

Number<unsigned short>&
ExecutionUnit::get_reg_dx () {
	return m_regs16[REG_DX];
}

void
ExecutionUnit::set_reg_dx (unsigned short val) {
	m_regs16[REG_DX] = val;
}

Number<unsigned char>&
ExecutionUnit::get_reg_dh () {
	return m_regs8[REG_DH];
}

void
ExecutionUnit::set_reg_dh (unsigned char val) {
	m_regs8[REG_DH] = val;
}

Number<unsigned char>&
ExecutionUnit::get_reg_dl () {
	return m_regs8[REG_DL];
}

void
ExecutionUnit::set_reg_dl (unsigned char val) {
	m_regs8[REG_DL] = val;
}

Number<unsigned short>&
ExecutionUnit::get_reg_di () {
	return m_regs16[REG_DI];
}

void
ExecutionUnit::set_reg_di (unsigned short val) {
	m_regs16[REG_DI] = val;
}

Number<unsigned short>&
ExecutionUnit::get_reg_si () {
	return m_regs16[REG_SI];
}

void
ExecutionUnit::set_reg_si (unsigned short val) {
	m_regs16[REG_SI] = val;
}

Number<unsigned short>&
ExecutionUnit::get_reg_bp () {
	return m_regs16[REG_BP];
}

void
ExecutionUnit::set_reg_bp (unsigned short val) {
	m_regs16[REG_BP] = val;
}

Number<unsigned short>&
ExecutionUnit::get_reg_sp () {
	return m_regs16[REG_SP];
}

void
ExecutionUnit::set_reg_sp (unsigned short val) {
	m_regs16[REG_SP] = val;
}

Number<unsigned short>&
ExecutionUnit::get_reg_flags () {
	return m_regs16[REG_FLAGS];
}

void
ExecutionUnit::set_reg_flags (unsigned short val) {
	m_regs16[REG_FLAGS] = val;
}

bool
ExecutionUnit::get_reg_flags_af () const {
	return Utility::get_bit (m_regs16[REG_FLAGS], 4);
}

void
ExecutionUnit::set_reg_flags_af (bool val) {
	if (val) {
		Utility::set_bit (m_regs16[REG_FLAGS], 4);
	}
	else {
		Utility::clear_bit (m_regs16[REG_FLAGS], 4);
	}
}

bool
ExecutionUnit::get_reg_flags_cf () const {
	return Utility::get_bit (m_regs16[REG_FLAGS], 0);
}

void
ExecutionUnit::set_reg_flags_cf (bool val) {
	if (val) {
		Utility::set_bit (m_regs16[REG_FLAGS], 0);
	}
	else {
		Utility::clear_bit (m_regs16[REG_FLAGS], 0);
	}
}

bool
ExecutionUnit::get_reg_flags_df () const {
	return Utility::get_bit (m_regs16[REG_FLAGS], 10);
}

void
ExecutionUnit::set_reg_flags_df (bool val) {
	if (val) {
		Utility::set_bit (m_regs16[REG_FLAGS], 10);
	}
	else {
		Utility::clear_bit (m_regs16[REG_FLAGS], 10);
	}
}

bool
ExecutionUnit::get_reg_flags_if () const {
	return Utility::get_bit (m_regs16[REG_FLAGS], 9);
}

void
ExecutionUnit::set_reg_flags_if (bool val) {
	if (val) {
		Utility::set_bit (m_regs16[REG_FLAGS], 9);
	}
	else {
		Utility::clear_bit (m_regs16[REG_FLAGS], 9);
	}
}

bool
ExecutionUnit::get_reg_flags_of () const {
	return Utility::get_bit (m_regs16[REG_FLAGS], 11);
}

void
ExecutionUnit::set_reg_flags_of (bool val) {
	if (val) {
		Utility::set_bit (m_regs16[REG_FLAGS], 11);
	}
	else {
		Utility::clear_bit (m_regs16[REG_FLAGS], 11);
	}
}

bool
ExecutionUnit::get_reg_flags_pf () const {
	return Utility::get_bit (m_regs16[REG_FLAGS], 2);
}

void
ExecutionUnit::set_reg_flags_pf (bool val) {
	if (val) {
		Utility::set_bit (m_regs16[REG_FLAGS], 2);
	}
	else {
		Utility::clear_bit (m_regs16[REG_FLAGS], 2);
	}
}

bool
ExecutionUnit::get_reg_flags_sf () const {
	return Utility::get_bit (m_regs16[REG_FLAGS], 7);
}

void
ExecutionUnit::set_reg_flags_sf (bool val) {
	if (val) {
		Utility::set_bit (m_regs16[REG_FLAGS], 7);
	}
	else {
		Utility::clear_bit (m_regs16[REG_FLAGS], 7);
	}
}

bool
ExecutionUnit::get_reg_flags_tf () const {
	return Utility::get_bit (m_regs16[REG_FLAGS], 8);
}

void
ExecutionUnit::set_reg_flags_tf (bool val) {
	if (val) {
		Utility::set_bit (m_regs16[REG_FLAGS], 8);
	}
	else {
		Utility::clear_bit (m_regs16[REG_FLAGS], 8);
	}
}

bool
ExecutionUnit::get_reg_flags_zf () const {
	return Utility::get_bit (m_regs16[REG_FLAGS], 6);
}

void
ExecutionUnit::set_reg_flags_zf (bool val) {
	if (val) {
		Utility::set_bit (m_regs16[REG_FLAGS], 6);
	}
	else {
		Utility::clear_bit (m_regs16[REG_FLAGS], 6);
	}
}

