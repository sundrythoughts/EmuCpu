#ifndef EXECUTION_UNIT_HH
#define EXECUTION_UNIT_HH

#include "BusInterfaceUnit.hh"
#include "Register.hh"
#include "Defines.hh"
#include <iostream>
#include <cstdio>
#include <sigc++/sigc++.h>

/**
*/
class ExecutionUnit {
	unsigned short m_regs[Jaf::REG_COUNT_16];
	Register<unsigned char> m_regs8[Jaf::REG_COUNT_8];
	Register<unsigned short> m_regs16[Jaf::REG_COUNT_16];

	BusInterfaceUnit *m_biu;

	sigc::signal<void, unsigned short> m_signal_value_changed_reg_flags;
	sigc::signal<void, bool> m_signal_value_changed_reg_flag_af;
	sigc::signal<void, bool> m_signal_value_changed_reg_flag_cf;
	sigc::signal<void, bool> m_signal_value_changed_reg_flag_df;
	sigc::signal<void, bool> m_signal_value_changed_reg_flag_if;
	sigc::signal<void, bool> m_signal_value_changed_reg_flag_of;
	sigc::signal<void, bool> m_signal_value_changed_reg_flag_pf;
	sigc::signal<void, bool> m_signal_value_changed_reg_flag_sf;
	sigc::signal<void, bool> m_signal_value_changed_reg_flag_tf;
	sigc::signal<void, bool> m_signal_value_changed_reg_flag_zf;

public:
	/** */
	ExecutionUnit () : m_biu (0)
	{
		unsigned char *m_a = (unsigned char*)&m_regs[Jaf::REG_AX];
		unsigned char *m_b = (unsigned char*)&m_regs[Jaf::REG_BX];
		unsigned char *m_c = (unsigned char*)&m_regs[Jaf::REG_CX];
		unsigned char *m_d = (unsigned char*)&m_regs[Jaf::REG_DX];

		m_regs8[Jaf::REG_AL].reinitialize (m_a[0]);
		m_regs8[Jaf::REG_AH].reinitialize (m_a[1]);
		m_regs8[Jaf::REG_BL].reinitialize (m_b[0]);
		m_regs8[Jaf::REG_BH].reinitialize (m_b[1]);
		m_regs8[Jaf::REG_CL].reinitialize (m_c[0]);
		m_regs8[Jaf::REG_CH].reinitialize (m_c[1]);
		m_regs8[Jaf::REG_DL].reinitialize (m_d[0]);
		m_regs8[Jaf::REG_DH].reinitialize (m_d[1]);

		m_regs16[Jaf::REG_AX].reinitialize (m_regs[Jaf::REG_AX]);
		m_regs16[Jaf::REG_BX].reinitialize (m_regs[Jaf::REG_BX]);
		m_regs16[Jaf::REG_CX].reinitialize (m_regs[Jaf::REG_CX]);
		m_regs16[Jaf::REG_DX].reinitialize (m_regs[Jaf::REG_DX]);
		m_regs16[Jaf::REG_DI].reinitialize (m_regs[Jaf::REG_DI]);
		m_regs16[Jaf::REG_SI].reinitialize (m_regs[Jaf::REG_SI]);
		m_regs16[Jaf::REG_BP].reinitialize (m_regs[Jaf::REG_BP]);
		m_regs16[Jaf::REG_SP].reinitialize (m_regs[Jaf::REG_SP]);
		m_regs16[Jaf::REG_FLAGS].reinitialize (m_regs[Jaf::REG_FLAGS]);
	}

	/** */
	ExecutionUnit (const ExecutionUnit &src);

	/** */
	~ExecutionUnit () {
	}

	/** */
	void connectTo (BusInterfaceUnit &biu);

	void connectToSignalValueChangedRegFlagsAF (const sigc::slot<void, bool> &slot);
	void connectToSignalValueChangedRegFlagsCF (const sigc::slot<void, bool> &slot);
	void connectToSignalValueChangedRegFlagsDF (const sigc::slot<void, bool> &slot);
	void connectToSignalValueChangedRegFlagsIF (const sigc::slot<void, bool> &slot);
	void connectToSignalValueChangedRegFlagsOF (const sigc::slot<void, bool> &slot);
	void connectToSignalValueChangedRegFlagsPF (const sigc::slot<void, bool> &slot);
	void connectToSignalValueChangedRegFlagsSF (const sigc::slot<void, bool> &slot);
	void connectToSignalValueChangedRegFlagsTF (const sigc::slot<void, bool> &slot);
	void connectToSignalValueChangedRegFlagsZF (const sigc::slot<void, bool> &slot);

	/** */
	BusInterfaceUnit& getBusInterfaceUnit ();

	/** */
	Register<unsigned char>& getReg8 (size_t index);

	/** */
	void setReg8 (size_t index, unsigned char val);

	/** */
	Register<unsigned short>& getReg16 (size_t index);

	/** */
	void setReg16 (size_t index, unsigned short val);

	/** */
	Register<unsigned short>& getRegAX ();

	/** */
	void setRegAX (unsigned short val);

	/** */
	Register<unsigned char>& getRegAH ();

	/** */
	void setRegAH (unsigned char val);

	/** */
	Register<unsigned char>& getRegAL ();

	/** */
	void setRegAL (unsigned char val);

	/** */
	Register<unsigned short>& getRegBX ();

	/** */
	void setRegBX (unsigned short val);

	/** */
	Register<unsigned char>& getRegBH ();

	/** */
	void setRegBH (unsigned char val);

	/** */
	Register<unsigned char>& getRegBL ();

	/** */
	void setRegBL (unsigned char val);

	/** */
	Register<unsigned short>& getRegCX ();

	/** */
	void setRegCX (unsigned short val);

	/** */
	Register<unsigned char>& getRegCH ();

	/** */
	void setRegCH (unsigned char val);

	/** */
	Register<unsigned char>& getRegCL ();

	/** */
	void setRegCL (unsigned char val);

	/** */
	Register<unsigned short>& getRegDX ();

	/** */
	void setRegDX (unsigned short val);

	/** */
	Register<unsigned char>& getRegDH ();

	/** */
	void setRegDH (unsigned char val);

	/** */
	Register<unsigned char>& getRegDL ();

	/** */
	void setRegDL (unsigned char val);

	/** */
	Register<unsigned short>& getRegDI ();

	/** */
	void setRegDI (unsigned short val);

	/** */
	Register<unsigned short>& getRegSI ();

	/** */
	void setRegSI (unsigned short val);

	/** */
	Register<unsigned short>& getRegBP ();

	/** */
	void setRegBP (unsigned short val);

	/** */
	Register<unsigned short>& getRegSP ();

	/** */
	void setRegSP (unsigned short val);

	/** */
	Register<unsigned short>& getRegFlags ();

	/** */
	void setRegFlags (unsigned short val);

	/** */
	bool getRegFlagsAF () const;

	/** */
	void setRegFlagsAF (bool val);

	/** */
	bool getRegFlagsCF () const;

	/** */
	void setRegFlagsCF (bool val);

	/** */
	bool getRegFlagsDF () const;

	/** */
	void setRegFlagsDF (bool val);

	/** */
	bool getRegFlagsIF () const;

	/** */
	void setRegFlagsIF (bool val);

	/** */
	bool getRegFlagsOF () const;

	/** */
	void setRegFlagsOF (bool val);

	/** */
	bool getRegFlagsPF () const;

	/** */
	void setRegFlagsPF (bool val);

	/** */
	bool getRegFlagsSF () const;

	/** */
	void setRegFlagsSF (bool val);

	/** */
	bool getRegFlagsTF () const;

	/** */
	void setRegFlagsTF (bool val);

	/** */
	bool getRegFlagsZF () const;

	/** */
	void setRegFlagsZF (bool val);

	void execAAA();
	void execAAD();
	void execAAM();
	void execAAS();
	void execADC();
	void execADD();
	void execAND();
	void execCALL();
	void execCALFAR();
	void execCBW();
	void execCLC();
	void execCLD();
	void execCLI();
	void execCMC();
	void execCMP();
	void execCMPS();
	void execCWD();
	void execDAA();
	void execDAS();
	void execDEC();
	void execDIV();
	void execESC();
	void execHLT();
	void execIDIV();
	void execIMUL();
	void execIN();
	void execINC();
	void execINT();
	void execINTO();
	void execIRET();
	void execJNBE();
	void execJNB();
	void execJNAE();
	void execJNA();
	void execJC();
	void execJCXZ();
	void execJE();
	void execJG();
	void execJGE();
	void execJL();
	void execJLE();
	void execJMP();
	void execJMPFAR();
	void execJNC();
	void execJNE();
	void execJNO();
	void execJNS();
	void execJNP();
	void execJO();
	void execJPE();
	void execJS();
	void execLAHF();
	void execLDS();
	void execLEA();
	void execLES();
	void execLOCK();
	void execLODS();
	void execLOOP();
	void execLOOPE();
	void execLOOPNE();
	void execMOV();
	void execMOVS();
	void execMUL();
	void execNEG();
	void execNOP();
	void execNOT();
	void execOR();
	void execOUT();
	void execPOP();
	void execPOPF();
	void execPUSH();
	void execPUSHF();
	void execRCL();
	void execRCR();
	void execREP();
	void execREPNE();
	void execRET();
	void execRETFAR();
	void execROL();
	void execROR();
	void execSAHF();
	void execSHL();
	void execSAR();
	void execSBB();
	void execSCAS();
	void execSEG();
	void execSHR();
	void execSTC();
	void execSTD();
	void execSTI();
	void execSTOS();
	void execSUB();
	void execTEST();
	void execWAIT();
	void execXCHG();
	void execXLAT();
	void execXOR();
};

#endif //EXECUTION_UNIT_HH

