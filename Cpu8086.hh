#ifndef CPU_8086_HH
#define CPU_8086_HH

#include "Cpu.hh"

class Cpu8086 : public Cpu {
	unsigned short _reg_ax;
	unsigned short _reg_bx;
	unsigned short _reg_cx;
	unsigned short _reg_dx;

	unsigned short _reg_di;
	unsigned short _reg_si;

	unsigned short _reg_bp;
	unsigned short _reg_sp;

	unsigned short _sreg_cs;
	unsigned short _sreg_ds;
	unsigned short _sreg_es;
	unsigned short _sreg_ss;

	unsigned short _reg_flags;

	unsigned short _reg_ip;

public:
	/** */
	unsigned short get_reg_ax () const;

	/** */
	void set_reg_ax (unsigned short val);

	/** */
	unsigned char get_reg_ah () const;

	/** */
	void set_reg_ah (unsigned char val);

	/** */
	unsigned char get_reg_al () const;

	/** */
	void set_reg_al (unsigned char val);

	/** */
	unsigned short get_reg_bx () const;

	/** */
	void set_reg_bx (unsigned short val);

	/** */
	unsigned char get_reg_bh () const;

	/** */
	void set_reg_bh (unsigned char val);

	/** */
	unsigned char get_reg_bl () const;

	/** */
	void set_reg_bl (unsigned char val);

	/** */
	unsigned short get_reg_cx () const;

	/** */
	void set_reg_cx (unsigned short val);

	/** */
	unsigned char get_reg_ch () const;

	/** */
	void set_reg_ch (unsigned char val);

	/** */
	unsigned char get_reg_cl () const;

	/** */
	void set_reg_cl (unsigned char val);

	/** */
	unsigned short get_reg_dx () const;

	/** */
	void set_reg_dx (unsigned short val);

	/** */
	unsigned char get_reg_dh () const;

	/** */
	void set_reg_dh (unsigned char val);

	/** */
	unsigned char get_reg_dl () const;

	/** */
	void set_reg_dl (unsigned char val);

	/** */
	unsigned short get_reg_di () const;

	/** */
	void set_reg_di (unsigned short val);

	/** */
	unsigned short get_reg_si () const;

	/** */
	void set_reg_si (unsigned short val);

	/** */
	unsigned short get_reg_bp () const;

	/** */
	void set_reg_bp (unsigned short val);

	/** */
	unsigned short get_reg_sp () const;

	/** */
	void set_reg_sp (unsigned short val);

	/** */
	unsigned short get_sreg_cs () const;

	/** */
	void set_sreg_cs (unsigned short val);

	/** */
	unsigned short get_sreg_ds () const;

	/** */
	void set_sreg_ds (unsigned short val);

	/** */
	unsigned short get_sreg_es () const;

	/** */
	void set_sreg_es (unsigned short val);

	/** */
	unsigned short get_sreg_ss () const;

	/** */
	void set_sreg_ss (unsigned short val);

	/** */
	unsigned short get_reg_flags () const;

	/** */
	void set_reg_flags (unsigned short val);

	/** */
	unsigned short get_reg_ip () const;

	/** */
	void set_reg_ip (unsigned short val);
};

#endif //CPU_8086_HH

