#ifndef EXECUTION_UNIT_HH
#define EXECUTION_UNIT_HH

#include "BusInterfaceUnit.hh"
#include "Number.hh"
#include <iostream>
#include <cstdio>

/**
*/
class ExecutionUnit {
	unsigned short m_ax;
	unsigned short m_bx;
	unsigned short m_cx;
	unsigned short m_dx;
	unsigned char *m_a;
	unsigned char *m_b;
	unsigned char *m_c;
	unsigned char *m_d;
	unsigned short m_di;
	unsigned short m_si;
	unsigned short m_bp;
	unsigned short m_sp;
	unsigned short m_flags;

	Number<unsigned short> m_reg_ax;
	Number<unsigned short> m_reg_bx;
	Number<unsigned short> m_reg_cx;
	Number<unsigned short> m_reg_dx;
	Number<unsigned char> m_reg_al;
	Number<unsigned char> m_reg_bl;
	Number<unsigned char> m_reg_cl;
	Number<unsigned char> m_reg_dl;
	Number<unsigned char> m_reg_ah;
	Number<unsigned char> m_reg_bh;
	Number<unsigned char> m_reg_ch;
	Number<unsigned char> m_reg_dh;
	Number<unsigned short> m_reg_di;
	Number<unsigned short> m_reg_si;
	Number<unsigned short> m_reg_bp;
	Number<unsigned short> m_reg_sp;
	Number<unsigned short> m_reg_flags;

	BusInterfaceUnit *m_biu;

public:
	/** */
	ExecutionUnit () : m_ax (0), m_bx (0), m_cx (0), m_dx (0),
	                   m_a ((unsigned char*)&m_ax), m_b ((unsigned char*)&m_bx),
	                   m_c ((unsigned char*)&m_cx), m_d ((unsigned char*)&m_dx),
	                   m_di (0), m_si (0), m_bp (0), m_sp (0), m_flags (0),
	                   m_reg_ax (m_ax), m_reg_bx (m_bx), m_reg_cx (m_cx), m_reg_dx (m_dx),
	                   m_reg_al (m_a[0]), m_reg_bl (m_b[0]), m_reg_cl (m_c[0]), m_reg_dl (m_d[0]),
	                   m_reg_ah (m_a[1]), m_reg_bh (m_b[1]), m_reg_ch (m_c[1]), m_reg_dh (m_d[1]),
	                   m_reg_di (m_di), m_reg_si (m_si), m_reg_bp (m_bp), m_reg_sp (m_sp), m_reg_flags (m_flags),
	                   m_biu (0)
	{
	}

	/** */
	ExecutionUnit (const ExecutionUnit &src);

	/** */
	~ExecutionUnit () {
	}

	/** */
	void connect_to (BusInterfaceUnit &biu);

	/** */
	BusInterfaceUnit& get_bus_interface_unit ();

	/** */
	Number<unsigned short>& get_reg_ax ();

	/** */
	void set_reg_ax (unsigned short val);

	/** */
	Number<unsigned char>& get_reg_ah ();

	/** */
	void set_reg_ah (unsigned char val);

	/** */
	Number<unsigned char>& get_reg_al ();

	/** */
	void set_reg_al (unsigned char val);

	/** */
	Number<unsigned short>& get_reg_bx ();

	/** */
	void set_reg_bx (unsigned short val);

	/** */
	Number<unsigned char>& get_reg_bh ();

	/** */
	void set_reg_bh (unsigned char val);

	/** */
	Number<unsigned char>& get_reg_bl ();

	/** */
	void set_reg_bl (unsigned char val);

	/** */
	Number<unsigned short>& get_reg_cx ();

	/** */
	void set_reg_cx (unsigned short val);

	/** */
	Number<unsigned char>& get_reg_ch ();

	/** */
	void set_reg_ch (unsigned char val);

	/** */
	Number<unsigned char>& get_reg_cl ();

	/** */
	void set_reg_cl (unsigned char val);

	/** */
	Number<unsigned short>& get_reg_dx ();

	/** */
	void set_reg_dx (unsigned short val);

	/** */
	Number<unsigned char>& get_reg_dh ();

	/** */
	void set_reg_dh (unsigned char val);

	/** */
	Number<unsigned char>& get_reg_dl ();

	/** */
	void set_reg_dl (unsigned char val);

	/** */
	Number<unsigned short>& get_reg_di ();

	/** */
	void set_reg_di (unsigned short val);

	/** */
	Number<unsigned short>& get_reg_si ();

	/** */
	void set_reg_si (unsigned short val);

	/** */
	Number<unsigned short>& get_reg_bp ();

	/** */
	void set_reg_bp (unsigned short val);

	/** */
	Number<unsigned short>& get_reg_sp ();

	/** */
	void set_reg_sp (unsigned short val);

	/** */
	Number<unsigned short>& get_reg_flags ();

	/** */
	void set_reg_flags (unsigned short val);

	/** */
	bool get_reg_flags_af () const;

	/** */
	void set_reg_flags_af (bool val);

	/** */
	bool get_reg_flags_cf () const;

	/** */
	void set_reg_flags_cf (bool val);

	/** */
	bool get_reg_flags_df () const;

	/** */
	void set_reg_flags_df (bool val);

	/** */
	bool get_reg_flags_if () const;

	/** */
	void set_reg_flags_if (bool val);

	/** */
	bool get_reg_flags_of () const;

	/** */
	void set_reg_flags_of (bool val);

	/** */
	bool get_reg_flags_pf () const;

	/** */
	void set_reg_flags_pf (bool val);

	/** */
	bool get_reg_flags_sf () const;

	/** */
	void set_reg_flags_sf (bool val);

	/** */
	bool get_reg_flags_tf () const;

	/** */
	void set_reg_flags_tf (bool val);

	/** */
	bool get_reg_flags_zf () const;

	/** */
	void set_reg_flags_zf (bool val);
};

#endif //EXECUTION_UNIT_HH

