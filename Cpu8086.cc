#include "Cpu8086.hh"

unsigned short
Cpu8086::get_reg_ax () const {
	return _reg_ax;
}

void
Cpu8086::set_reg_ax (unsigned short val) {
	_reg_ax = val;
}

unsigned char
Cpu8086::get_reg_ah () const {
	unsigned char *al_ah = (unsigned char*)&_reg_ax;
	return al_ah[1];
}

void
Cpu8086::set_reg_ah (unsigned char val) {
	char *al_ah = (char*)&_reg_ax;
	al_ah[1] = val;
}

unsigned char
Cpu8086::get_reg_al () const {
	unsigned char *al_ah = (unsigned char*)&_reg_ax;
	return al_ah[0];
}

void
Cpu8086::set_reg_al (unsigned char val) {
	unsigned char *al_ah = (unsigned char*)&_reg_ax;
	al_ah[0] = val;
}

unsigned short
Cpu8086::get_reg_bx () const {
	return _reg_bx;
}

void
Cpu8086::set_reg_bx (unsigned short val) {
	_reg_bx = val;
}

unsigned char
Cpu8086::get_reg_bh () const {
	unsigned char *bl_bh = (unsigned char*)&_reg_bx;
	return bl_bh[1];
}

void
Cpu8086::set_reg_bh (unsigned char val) {
	unsigned char *bl_bh = (unsigned char*)&_reg_bx;
	bl_bh[1] = val;
}

unsigned char
Cpu8086::get_reg_bl () const {
	unsigned char *bl_bh = (unsigned char*)&_reg_bx;
	return bl_bh[0];
}

void
Cpu8086::set_reg_bl (unsigned char val) {
	unsigned char *bl_bh = (unsigned char*)&_reg_bx;
	bl_bh[0] = val;
}

unsigned short
Cpu8086::get_reg_cx () const {
	return _reg_cx;
}

void
Cpu8086::set_reg_cx (unsigned short val) {
	_reg_cx = val;
}

unsigned char
Cpu8086::get_reg_ch () const {
	unsigned char *cl_ch = (unsigned char*)&_reg_cx;
	return cl_ch[1];
}

void
Cpu8086::set_reg_ch (unsigned char val) {
	unsigned char *cl_ch = (unsigned char*)&_reg_cx;
	cl_ch[1] = val;
}

unsigned char
Cpu8086::get_reg_cl () const {
	unsigned char *cl_ch = (unsigned char*)&_reg_cx;
	return cl_ch[0];
}

void
Cpu8086::set_reg_cl (unsigned char val) {
	unsigned char *cl_ch = (unsigned char*)&_reg_cx;
	cl_ch[0] = val;
}

unsigned short
Cpu8086::get_reg_dx () const {
	return _reg_dx;
}

void
Cpu8086::set_reg_dx (unsigned short val) {
	_reg_dx = val;
}

unsigned char
Cpu8086::get_reg_dh () const {
	unsigned char *dl_dh = (unsigned char*)&_reg_dx;
	return dl_dh[1];
}

void
Cpu8086::set_reg_dh (unsigned char val) {
	unsigned char *dl_dh = (unsigned char*)&_reg_dx;
	dl_dh[1] = val;
}

unsigned char
Cpu8086::get_reg_dl () const {
	unsigned char *dl_dh = (unsigned char*)&_reg_dx;
	return dl_dh[0];
}

void
Cpu8086::set_reg_dl (unsigned char val) {
	unsigned char *dl_dh = (unsigned char*)&_reg_dx;
	dl_dh[0] = val;
}

unsigned short
Cpu8086::get_reg_di () const {
	return _reg_di;
}

void
Cpu8086::set_reg_di (unsigned short val) {
	_reg_di = val;
}

unsigned short
Cpu8086::get_reg_si () const {
	return _reg_si;
}

void
Cpu8086::set_reg_si (unsigned short val) {
	_reg_si = val;
}

unsigned short
Cpu8086::get_reg_bp () const {
	return _reg_bp;
}

void
Cpu8086::set_reg_bp (unsigned short val) {
	_reg_bp = val;
}

unsigned short
Cpu8086::get_reg_sp () const {
	return _reg_sp;
}

void
Cpu8086::set_reg_sp (unsigned short val) {
	_reg_sp = val;
}

unsigned short
Cpu8086::get_sreg_cs () const {
	return _sreg_cs;
}

void
Cpu8086::set_sreg_cs (unsigned short val) {
	_sreg_cs = val;
}

unsigned short
Cpu8086::get_sreg_ds () const {
	return _sreg_ds;
}

void
Cpu8086::set_sreg_ds (unsigned short val) {
	_sreg_ds = val;
}

unsigned short
Cpu8086::get_sreg_es () const {
	return _sreg_es;
}

void
Cpu8086::set_sreg_es (unsigned short val) {
	_sreg_es = val;
}

unsigned short
Cpu8086::get_sreg_ss () const {
	return _sreg_ss;
}

void
Cpu8086::set_sreg_ss (unsigned short val) {
	_sreg_ss = val;
}

unsigned short
Cpu8086::get_reg_flags () const {
	return _reg_flags;
}

void
Cpu8086::set_reg_flags (unsigned short val) {
	_reg_flags = val;
}

unsigned short
Cpu8086::get_reg_ip () const {
	return _reg_ip;
}

void
Cpu8086::set_reg_ip (unsigned short val) {
	_reg_ip = val;
}

