#include "ExecutionUnit.hh"
#include "Utility.hh"

void
ExecutionUnit::connect_to (BusInterfaceUnit &biu) {
	m_biu = &biu;

	//FIXME - connect to signals
}

unsigned short
ExecutionUnit::get_reg_ax () const {
	return m_reg_ax;
}

void
ExecutionUnit::set_reg_ax (unsigned short val) {
	m_reg_ax = val;
}

unsigned char
ExecutionUnit::get_reg_ah () const {
	unsigned char *al_ah = (unsigned char*)&m_reg_ax;
	return al_ah[1];
}

void
ExecutionUnit::set_reg_ah (unsigned char val) {
	char *al_ah = (char*)&m_reg_ax;
	al_ah[1] = val;
}

unsigned char
ExecutionUnit::get_reg_al () const {
	unsigned char *al_ah = (unsigned char*)&m_reg_ax;
	return al_ah[0];
}

void
ExecutionUnit::set_reg_al (unsigned char val) {
	unsigned char *al_ah = (unsigned char*)&m_reg_ax;
	al_ah[0] = val;
}

unsigned short
ExecutionUnit::get_reg_bx () const {
	return m_reg_bx;
}

void
ExecutionUnit::set_reg_bx (unsigned short val) {
	m_reg_bx = val;
}

unsigned char
ExecutionUnit::get_reg_bh () const {
	unsigned char *bl_bh = (unsigned char*)&m_reg_bx;
	return bl_bh[1];
}

void
ExecutionUnit::set_reg_bh (unsigned char val) {
	unsigned char *bl_bh = (unsigned char*)&m_reg_bx;
	bl_bh[1] = val;
}

unsigned char
ExecutionUnit::get_reg_bl () const {
	unsigned char *bl_bh = (unsigned char*)&m_reg_bx;
	return bl_bh[0];
}

void
ExecutionUnit::set_reg_bl (unsigned char val) {
	unsigned char *bl_bh = (unsigned char*)&m_reg_bx;
	bl_bh[0] = val;
}

unsigned short
ExecutionUnit::get_reg_cx () const {
	return m_reg_cx;
}

void
ExecutionUnit::set_reg_cx (unsigned short val) {
	m_reg_cx = val;
}

unsigned char
ExecutionUnit::get_reg_ch () const {
	unsigned char *cl_ch = (unsigned char*)&m_reg_cx;
	return cl_ch[1];
}

void
ExecutionUnit::set_reg_ch (unsigned char val) {
	unsigned char *cl_ch = (unsigned char*)&m_reg_cx;
	cl_ch[1] = val;
}

unsigned char
ExecutionUnit::get_reg_cl () const {
	unsigned char *cl_ch = (unsigned char*)&m_reg_cx;
	return cl_ch[0];
}

void
ExecutionUnit::set_reg_cl (unsigned char val) {
	unsigned char *cl_ch = (unsigned char*)&m_reg_cx;
	cl_ch[0] = val;
}

unsigned short
ExecutionUnit::get_reg_dx () const {
	return m_reg_dx;
}

void
ExecutionUnit::set_reg_dx (unsigned short val) {
	m_reg_dx = val;
}

unsigned char
ExecutionUnit::get_reg_dh () const {
	unsigned char *dl_dh = (unsigned char*)&m_reg_dx;
	return dl_dh[1];
}

void
ExecutionUnit::set_reg_dh (unsigned char val) {
	unsigned char *dl_dh = (unsigned char*)&m_reg_dx;
	dl_dh[1] = val;
}

unsigned char
ExecutionUnit::get_reg_dl () const {
	unsigned char *dl_dh = (unsigned char*)&m_reg_dx;
	return dl_dh[0];
}

void
ExecutionUnit::set_reg_dl (unsigned char val) {
	unsigned char *dl_dh = (unsigned char*)&m_reg_dx;
	dl_dh[0] = val;
}

unsigned short
ExecutionUnit::get_reg_di () const {
	return m_reg_di;
}

void
ExecutionUnit::set_reg_di (unsigned short val) {
	m_reg_di = val;
}

unsigned short
ExecutionUnit::get_reg_si () const {
	return m_reg_si;
}

void
ExecutionUnit::set_reg_si (unsigned short val) {
	m_reg_si = val;
}

unsigned short
ExecutionUnit::get_reg_bp () const {
	return m_reg_bp;
}

void
ExecutionUnit::set_reg_bp (unsigned short val) {
	m_reg_bp = val;
}

unsigned short
ExecutionUnit::get_reg_sp () const {
	return m_reg_sp;
}

void
ExecutionUnit::set_reg_sp (unsigned short val) {
	m_reg_sp = val;
}

unsigned short
ExecutionUnit::get_reg_flags () const {
	return m_reg_flags;
}

void
ExecutionUnit::set_reg_flags (unsigned short val) {
	m_reg_flags = val;
}

bool
ExecutionUnit::get_reg_flags_af () const {
	return Utility::get_bit (m_reg_flags, 4);
}

void
ExecutionUnit::set_reg_flags_af (bool val) {
	if (val) {
		Utility::set_bit (m_reg_flags, 4);
	}
	else {
		Utility::clear_bit (m_reg_flags, 4);
	}
}

bool
ExecutionUnit::get_reg_flags_cf () const {
	return Utility::get_bit (m_reg_flags, 0);
}

void
ExecutionUnit::set_reg_flags_cf (bool val) {
	if (val) {
		Utility::set_bit (m_reg_flags, 0);
	}
	else {
		Utility::clear_bit (m_reg_flags, 0);
	}
}

bool
ExecutionUnit::get_reg_flags_df () const {
	return Utility::get_bit (m_reg_flags, 10);
}

void
ExecutionUnit::set_reg_flags_df (bool val) {
	if (val) {
		Utility::set_bit (m_reg_flags, 10);
	}
	else {
		Utility::clear_bit (m_reg_flags, 10);
	}
}

bool
ExecutionUnit::get_reg_flags_if () const {
	return Utility::get_bit (m_reg_flags, 9);
}

void
ExecutionUnit::set_reg_flags_if (bool val) {
	if (val) {
		Utility::set_bit (m_reg_flags, 9);
	}
	else {
		Utility::clear_bit (m_reg_flags, 9);
	}
}

bool
ExecutionUnit::get_reg_flags_of () const {
	return Utility::get_bit (m_reg_flags, 11);
}

void
ExecutionUnit::set_reg_flags_of (bool val) {
	if (val) {
		Utility::set_bit (m_reg_flags, 11);
	}
	else {
		Utility::clear_bit (m_reg_flags, 11);
	}
}

bool
ExecutionUnit::get_reg_flags_pf () const {
	return Utility::get_bit (m_reg_flags, 2);
}

void
ExecutionUnit::set_reg_flags_pf (bool val) {
	if (val) {
		Utility::set_bit (m_reg_flags, 2);
	}
	else {
		Utility::clear_bit (m_reg_flags, 2);
	}
}

bool
ExecutionUnit::get_reg_flags_sf () const {
	return Utility::get_bit (m_reg_flags, 7);
}

void
ExecutionUnit::set_reg_flags_sf (bool val) {
	if (val) {
		Utility::set_bit (m_reg_flags, 7);
	}
	else {
		Utility::clear_bit (m_reg_flags, 7);
	}
}

bool
ExecutionUnit::get_reg_flags_tf () const {
	return Utility::get_bit (m_reg_flags, 8);
}

void
ExecutionUnit::set_reg_flags_tf (bool val) {
	if (val) {
		Utility::set_bit (m_reg_flags, 8);
	}
	else {
		Utility::clear_bit (m_reg_flags, 8);
	}
}

bool
ExecutionUnit::get_reg_flags_zf () const {
	return Utility::get_bit (m_reg_flags, 6);
}

void
ExecutionUnit::set_reg_flags_zf (bool val) {
	if (val) {
		Utility::set_bit (m_reg_flags, 6);
	}
	else {
		Utility::clear_bit (m_reg_flags, 6);
	}
}

