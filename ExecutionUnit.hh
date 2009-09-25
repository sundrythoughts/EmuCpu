#ifndef EXECUTION_UNIT_HH
#define EXECUTION_UNIT_HH

#include "BusInterfaceUnit.hh"
#include "Number.hh"
#include "Defines.hh"
#include <iostream>
#include <cstdio>

/**
*/
class ExecutionUnit {
	unsigned short m_regs[REG_COUNT_16];
	Number<unsigned char> m_regs8[REG_COUNT_8];
	Number<unsigned short> m_regs16[REG_COUNT_16];

	BusInterfaceUnit *m_biu;

public:
	/** */
	ExecutionUnit () : m_biu (0)
	{
		unsigned char *m_a = (unsigned char*)&m_regs[REG_AX];
		unsigned char *m_b = (unsigned char*)&m_regs[REG_BX];
		unsigned char *m_c = (unsigned char*)&m_regs[REG_CX];
		unsigned char *m_d = (unsigned char*)&m_regs[REG_DX];

		m_regs8[REG_AL].reinitialize (m_a[0]);
		m_regs8[REG_AH].reinitialize (m_a[1]);
		m_regs8[REG_BL].reinitialize (m_b[0]);
		m_regs8[REG_BH].reinitialize (m_b[1]);
		m_regs8[REG_CL].reinitialize (m_c[0]);
		m_regs8[REG_CH].reinitialize (m_c[1]);
		m_regs8[REG_DL].reinitialize (m_d[0]);
		m_regs8[REG_DH].reinitialize (m_d[1]);

		m_regs16[REG_AX].reinitialize (m_regs[REG_AX]);
		m_regs16[REG_BX].reinitialize (m_regs[REG_BX]);
		m_regs16[REG_CX].reinitialize (m_regs[REG_CX]);
		m_regs16[REG_DX].reinitialize (m_regs[REG_DX]);
		m_regs16[REG_DI].reinitialize (m_regs[REG_DI]);
		m_regs16[REG_SI].reinitialize (m_regs[REG_SI]);
		m_regs16[REG_BP].reinitialize (m_regs[REG_BP]);
		m_regs16[REG_SP].reinitialize (m_regs[REG_SP]);
		m_regs16[REG_FLAGS].reinitialize (m_regs[REG_FLAGS]);
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

