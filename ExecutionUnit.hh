#ifndef EXECUTION_UNIT_HH
#define EXECUTION_UNIT_HH

#include "BusInterfaceUnit.hh"

class ExecutionUnit {
	unsigned short m_reg_ax;
	unsigned short m_reg_bx;
	unsigned short m_reg_cx;
	unsigned short m_reg_dx;

	unsigned short m_reg_di;
	unsigned short m_reg_si;

	unsigned short m_reg_bp;
	unsigned short m_reg_sp;

	unsigned short m_reg_flags;

	BusInterfaceUnit *m_biu;

public:
	ExecutionUnit () {
		m_reg_ax = 0;
		m_reg_bx = 0;
		m_reg_cx = 0;
		m_reg_dx = 0;

		m_reg_di = 0;
		m_reg_si = 0;

		m_reg_bp = 0;
		m_reg_sp = 0;

		m_reg_flags = 0;

		m_biu = 0;
	}

	ExecutionUnit (const ExecutionUnit &src);

	~ExecutionUnit () {
	}

	/** */
	void connect_to (BusInterfaceUnit &biu);

	BusInterfaceUnit& get_bus_interface_unit ();

	/** */
	unsigned short& get_reg_ax ();

	/** */
	void set_reg_ax (unsigned short val);

	/** */
	unsigned char& get_reg_ah ();

	/** */
	void set_reg_ah (unsigned char val);

	/** */
	unsigned char& get_reg_al ();

	/** */
	void set_reg_al (unsigned char val);

	/** */
	unsigned short& get_reg_bx ();

	/** */
	void set_reg_bx (unsigned short val);

	/** */
	unsigned char& get_reg_bh ();

	/** */
	void set_reg_bh (unsigned char val);

	/** */
	unsigned char& get_reg_bl ();

	/** */
	void set_reg_bl (unsigned char val);

	/** */
	unsigned short& get_reg_cx ();

	/** */
	void set_reg_cx (unsigned short val);

	/** */
	unsigned char& get_reg_ch ();

	/** */
	void set_reg_ch (unsigned char val);

	/** */
	unsigned char& get_reg_cl ();

	/** */
	void set_reg_cl (unsigned char val);

	/** */
	unsigned short& get_reg_dx ();

	/** */
	void set_reg_dx (unsigned short val);

	/** */
	unsigned char& get_reg_dh ();

	/** */
	void set_reg_dh (unsigned char val);

	/** */
	unsigned char& get_reg_dl ();

	/** */
	void set_reg_dl (unsigned char val);

	/** */
	unsigned short& get_reg_di ();

	/** */
	void set_reg_di (unsigned short val);

	/** */
	unsigned short& get_reg_si ();

	/** */
	void set_reg_si (unsigned short val);

	/** */
	unsigned short& get_reg_bp ();

	/** */
	void set_reg_bp (unsigned short val);

	/** */
	unsigned short& get_reg_sp ();

	/** */
	void set_reg_sp (unsigned short val);

	/** */
	unsigned short& get_reg_flags ();

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

