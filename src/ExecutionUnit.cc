#include "ExecutionUnit.hh"
#include "Cpu.hh"
#include "BusInterfaceUnit.hh"
#include "ArithmeticLogicUnit.hh"
#include "Utility.hh"
#include "InstructionExecuter.hh"


class ExecutionUnitPrivate {
public:
	unsigned short m_regs[Jaf::REG_COUNT_16];
	Register<unsigned char> m_regs8[Jaf::REG_COUNT_8];
	Register<unsigned short> m_regs16[Jaf::REG_COUNT_16];

	Cpu *m_cpu;
	BusInterfaceUnit *m_biu;
	ArithmeticLogicUnit *m_alu;

	//sigc::signal<void, unsigned short> m_signal_value_changed_reg_flags;
	sigc::signal<void, bool> m_signal_value_changed_reg_flag_af;
	sigc::signal<void, bool> m_signal_value_changed_reg_flag_cf;
	sigc::signal<void, bool> m_signal_value_changed_reg_flag_df;
	sigc::signal<void, bool> m_signal_value_changed_reg_flag_if;
	sigc::signal<void, bool> m_signal_value_changed_reg_flag_of;
	sigc::signal<void, bool> m_signal_value_changed_reg_flag_pf;
	sigc::signal<void, bool> m_signal_value_changed_reg_flag_sf;
	sigc::signal<void, bool> m_signal_value_changed_reg_flag_tf;
	sigc::signal<void, bool> m_signal_value_changed_reg_flag_zf;
};

/** */
ExecutionUnit::ExecutionUnit () {
	p = new ExecutionUnitPrivate ();

	unsigned char *m_a = (unsigned char*)&p->m_regs[Jaf::REG_AX];
	unsigned char *m_b = (unsigned char*)&p->m_regs[Jaf::REG_BX];
	unsigned char *m_c = (unsigned char*)&p->m_regs[Jaf::REG_CX];
	unsigned char *m_d = (unsigned char*)&p->m_regs[Jaf::REG_DX];

	p->m_regs8[Jaf::REG_AL].reinitialize (m_a[0]);
	p->m_regs8[Jaf::REG_AH].reinitialize (m_a[1]);
	p->m_regs8[Jaf::REG_BL].reinitialize (m_b[0]);
	p->m_regs8[Jaf::REG_BH].reinitialize (m_b[1]);
	p->m_regs8[Jaf::REG_CL].reinitialize (m_c[0]);
	p->m_regs8[Jaf::REG_CH].reinitialize (m_c[1]);
	p->m_regs8[Jaf::REG_DL].reinitialize (m_d[0]);
	p->m_regs8[Jaf::REG_DH].reinitialize (m_d[1]);

	p->m_regs16[Jaf::REG_AX].reinitialize (p->m_regs[Jaf::REG_AX]);
	p->m_regs16[Jaf::REG_BX].reinitialize (p->m_regs[Jaf::REG_BX]);
	p->m_regs16[Jaf::REG_CX].reinitialize (p->m_regs[Jaf::REG_CX]);
	p->m_regs16[Jaf::REG_DX].reinitialize (p->m_regs[Jaf::REG_DX]);
	p->m_regs16[Jaf::REG_DI].reinitialize (p->m_regs[Jaf::REG_DI]);
	p->m_regs16[Jaf::REG_SI].reinitialize (p->m_regs[Jaf::REG_SI]);
	p->m_regs16[Jaf::REG_BP].reinitialize (p->m_regs[Jaf::REG_BP]);
	p->m_regs16[Jaf::REG_SP].reinitialize (p->m_regs[Jaf::REG_SP]);
	p->m_regs16[Jaf::REG_FLAGS].reinitialize (p->m_regs[Jaf::REG_FLAGS]);
}

ExecutionUnit::~ExecutionUnit () {
	delete p;
}

/** */
void
ExecutionUnit::connectTo (Cpu &cpu) {
	p->m_cpu = &cpu;
	p->m_biu = &cpu.getBusInterfaceUnit ();
	p->m_alu = &cpu.getArithmeticLogicUnit ();
}

sigc::signal<void, bool>&
ExecutionUnit::signalValueChangedRegFlagsAF () {
	return p->m_signal_value_changed_reg_flag_af;
}

sigc::signal<void, bool>&
ExecutionUnit::signalValueChangedRegFlagsCF () {
	return p->m_signal_value_changed_reg_flag_cf;
}

sigc::signal<void, bool>&
ExecutionUnit::signalValueChangedRegFlagsDF () {
	return p->m_signal_value_changed_reg_flag_df;
}

sigc::signal<void, bool>&
ExecutionUnit::signalValueChangedRegFlagsIF () {
	return p->m_signal_value_changed_reg_flag_if;
}

sigc::signal<void, bool>&
ExecutionUnit::signalValueChangedRegFlagsOF () {
	return p->m_signal_value_changed_reg_flag_of;
}

sigc::signal<void, bool>&
ExecutionUnit::signalValueChangedRegFlagsPF () {
	return p->m_signal_value_changed_reg_flag_pf;
}

sigc::signal<void, bool>&
ExecutionUnit::signalValueChangedRegFlagsSF () {
	return p->m_signal_value_changed_reg_flag_sf;
}

sigc::signal<void, bool>&
ExecutionUnit::signalValueChangedRegFlagsTF () {
	return p->m_signal_value_changed_reg_flag_tf;
}

sigc::signal<void, bool>&
ExecutionUnit::signalValueChangedRegFlagsZF () {
	return p->m_signal_value_changed_reg_flag_zf;
}

Register<unsigned char>&
ExecutionUnit::getReg8 (size_t index) {
	return p->m_regs8[index]; //FIXME - no bounds checking
}

void
ExecutionUnit::setReg8 (size_t index, unsigned char val) {
	p->m_regs8[index] = val; //FIXME - no bounds checking
}

Register<unsigned short>&
ExecutionUnit::getReg16 (size_t index) {
	return p->m_regs16[index]; //FIXME - no bounds checking
}

void
ExecutionUnit::setReg16 (size_t index, unsigned short val) {
	p->m_regs16[index] = val; //FIXME - no bounds checking
}

Register<unsigned short>&
ExecutionUnit::getRegAX () {
	return p->m_regs16[Jaf::REG_AX];
}

void
ExecutionUnit::setRegAX (unsigned short val) {
	p->m_regs16[Jaf::REG_AX] = val;
}

Register<unsigned char>&
ExecutionUnit::getRegAH () {
	return p->m_regs8[Jaf::REG_AH];
}

void
ExecutionUnit::setRegAH (unsigned char val) {
	p->m_regs8[Jaf::REG_AH] = val;
}

Register<unsigned char>&
ExecutionUnit::getRegAL () {
	return p->m_regs8[Jaf::REG_AL];
}

void
ExecutionUnit::setRegAL (unsigned char val) {
	p->m_regs8[Jaf::REG_AL] = val;
}

Register<unsigned short>&
ExecutionUnit::getRegBX () {
	return p->m_regs16[Jaf::REG_BX];
}

void
ExecutionUnit::setRegBX (unsigned short val) {
	p->m_regs16[Jaf::REG_BX] = val;
}

Register<unsigned char>&
ExecutionUnit::getRegBH () {
	return p->m_regs8[Jaf::REG_BH];
}

void
ExecutionUnit::setRegBH (unsigned char val) {
	p->m_regs8[Jaf::REG_BH] = val;
}

Register<unsigned char>&
ExecutionUnit::getRegBL () {
	return p->m_regs8[Jaf::REG_BL];
}

void
ExecutionUnit::setRegBL (unsigned char val) {
	p->m_regs8[Jaf::REG_BL] = val;
}

Register<unsigned short>&
ExecutionUnit::getRegCX () {
	return p->m_regs16[Jaf::REG_CX];
}

void
ExecutionUnit::setRegCX (unsigned short val) {
	p->m_regs16[Jaf::REG_CX] = val;
}

Register<unsigned char>&
ExecutionUnit::getRegCH () {
	return p->m_regs8[Jaf::REG_CH];
}

void
ExecutionUnit::setRegCH (unsigned char val) {
	p->m_regs8[Jaf::REG_CH] = val;
}

Register<unsigned char>&
ExecutionUnit::getRegCL () {
	return p->m_regs8[Jaf::REG_CL];
}

void
ExecutionUnit::setRegCL (unsigned char val) {
	p->m_regs8[Jaf::REG_CL] = val;
}

Register<unsigned short>&
ExecutionUnit::getRegDX () {
	return p->m_regs16[Jaf::REG_DX];
}

void
ExecutionUnit::setRegDX (unsigned short val) {
	p->m_regs16[Jaf::REG_DX] = val;
}

Register<unsigned char>&
ExecutionUnit::getRegDH () {
	return p->m_regs8[Jaf::REG_DH];
}

void
ExecutionUnit::setRegDH (unsigned char val) {
	p->m_regs8[Jaf::REG_DH] = val;
}

Register<unsigned char>&
ExecutionUnit::getRegDL () {
	return p->m_regs8[Jaf::REG_DL];
}

void
ExecutionUnit::setRegDL (unsigned char val) {
	p->m_regs8[Jaf::REG_DL] = val;
}

Register<unsigned short>&
ExecutionUnit::getRegDI () {
	return p->m_regs16[Jaf::REG_DI];
}

void
ExecutionUnit::setRegDI (unsigned short val) {
	p->m_regs16[Jaf::REG_DI] = val;
}

Register<unsigned short>&
ExecutionUnit::getRegSI () {
	return p->m_regs16[Jaf::REG_SI];
}

void
ExecutionUnit::setRegSI (unsigned short val) {
	p->m_regs16[Jaf::REG_SI] = val;
}

Register<unsigned short>&
ExecutionUnit::getRegBP () {
	return p->m_regs16[Jaf::REG_BP];
}

void
ExecutionUnit::setRegBP (unsigned short val) {
	p->m_regs16[Jaf::REG_BP] = val;
}

Register<unsigned short>&
ExecutionUnit::getRegSP () {
	return p->m_regs16[Jaf::REG_SP];
}

void
ExecutionUnit::setRegSP (unsigned short val) {
	p->m_regs16[Jaf::REG_SP] = val;
}

Register<unsigned short>&
ExecutionUnit::getRegFlags () {
	return p->m_regs16[Jaf::REG_FLAGS];
}

void
ExecutionUnit::setRegFlags (unsigned short val) {
	p->m_regs16[Jaf::REG_FLAGS] = val;
}

bool
ExecutionUnit::getRegFlagsAF () const {
	return Utility::get_bit (p->m_regs16[Jaf::REG_FLAGS], 4);
}

void
ExecutionUnit::setRegFlagsAF (bool val) {
	if (val) {
		Utility::set_bit (p->m_regs16[Jaf::REG_FLAGS], 4);
	}
	else {
		Utility::clear_bit (p->m_regs16[Jaf::REG_FLAGS], 4);
	}

	//FIXME
	//p->m_signal_value_changed_reg_flag_af.emit (getRegFlagsAF ());
}

bool
ExecutionUnit::getRegFlagsCF () const {
	return Utility::get_bit (p->m_regs16[Jaf::REG_FLAGS], 0);
}

void
ExecutionUnit::setRegFlagsCF (bool val) {
	if (val) {
		Utility::set_bit (p->m_regs16[Jaf::REG_FLAGS], 0);
	}
	else {
		Utility::clear_bit (p->m_regs16[Jaf::REG_FLAGS], 0);
	}

	//FIXME
	//p->m_signal_value_changed_reg_flag_cf.emit (getRegFlagsCF ());
}

bool
ExecutionUnit::getRegFlagsDF () const {
	return Utility::get_bit (p->m_regs16[Jaf::REG_FLAGS], 10);
}

void
ExecutionUnit::setRegFlagsDF (bool val) {
	if (val) {
		Utility::set_bit (p->m_regs16[Jaf::REG_FLAGS], 10);
	}
	else {
		Utility::clear_bit (p->m_regs16[Jaf::REG_FLAGS], 10);
	}

	//FIXME
	//p->m_signal_value_changed_reg_flag_df.emit (getRegFlagsDF ());
}

bool
ExecutionUnit::getRegFlagsIF () const {
	return Utility::get_bit (p->m_regs16[Jaf::REG_FLAGS], 9);
}

void
ExecutionUnit::setRegFlagsIF (bool val) {
	if (val) {
		Utility::set_bit (p->m_regs16[Jaf::REG_FLAGS], 9);
	}
	else {
		Utility::clear_bit (p->m_regs16[Jaf::REG_FLAGS], 9);
	}

	//FIXME
	//p->m_signal_value_changed_reg_flag_if.emit (getRegFlagsIF ());
}

bool
ExecutionUnit::getRegFlagsOF () const {
	return Utility::get_bit (p->m_regs16[Jaf::REG_FLAGS], 11);
}

void
ExecutionUnit::setRegFlagsOF (bool val) {
	if (val) {
		Utility::set_bit (p->m_regs16[Jaf::REG_FLAGS], 11);
	}
	else {
		Utility::clear_bit (p->m_regs16[Jaf::REG_FLAGS], 11);
	}

	//FIXME
	//p->m_signal_value_changed_reg_flag_of.emit (getRegFlagsOF ());
}

bool
ExecutionUnit::getRegFlagsPF () const {
	return Utility::get_bit (p->m_regs16[Jaf::REG_FLAGS], 2);
}

void
ExecutionUnit::setRegFlagsPF (bool val) {
	if (val) {
		Utility::set_bit (p->m_regs16[Jaf::REG_FLAGS], 2);
	}
	else {
		Utility::clear_bit (p->m_regs16[Jaf::REG_FLAGS], 2);
	}

	//FIXME
	//p->m_signal_value_changed_reg_flag_pf.emit (getRegFlagsPF ());
}

bool
ExecutionUnit::getRegFlagsSF () const {
	return Utility::get_bit (p->m_regs16[Jaf::REG_FLAGS], 7);
}

void
ExecutionUnit::setRegFlagsSF (bool val) {
	if (val) {
		Utility::set_bit (p->m_regs16[Jaf::REG_FLAGS], 7);
	}
	else {
		Utility::clear_bit (p->m_regs16[Jaf::REG_FLAGS], 7);
	}

	//FIXME
	//p->m_signal_value_changed_reg_flag_sf.emit (getRegFlagsSF ());
}

bool
ExecutionUnit::getRegFlagsTF () const {
	return Utility::get_bit (p->m_regs16[Jaf::REG_FLAGS], 8);
}

void
ExecutionUnit::setRegFlagsTF (bool val) {
	if (val) {
		Utility::set_bit (p->m_regs16[Jaf::REG_FLAGS], 8);
	}
	else {
		Utility::clear_bit (p->m_regs16[Jaf::REG_FLAGS], 8);
	}

	//FIXME
	//p->m_signal_value_changed_reg_flag_tf.emit (getRegFlagsTF ());
}

bool
ExecutionUnit::getRegFlagsZF () const {
	return Utility::get_bit (p->m_regs16[Jaf::REG_FLAGS], 6);
}

void
ExecutionUnit::setRegFlagsZF (bool val) {
	if (val) {
		Utility::set_bit (p->m_regs16[Jaf::REG_FLAGS], 6);
	}
	else {
		Utility::clear_bit (p->m_regs16[Jaf::REG_FLAGS], 6);
	}

	//p->m_signal_value_changed_reg_flag_zf.emit (getRegFlagsZF ());
}

void
ExecutionUnit::execADD (std::vector<NumberWrapper> &ops) {
	if (ops[0].size () == sizeof(unsigned short)) {
		//execADD (ops[0].get<unsigned short> (), ops[1].get<unsigned short> ());
		unsigned short ret;
		p->m_alu->opAdd (ops[0].get<unsigned short> (), ops[1].get<unsigned short> (), ret);
		ops[0].get<unsigned short> () = ret;

		//FIXME - debugging
		//std::cout << ops[0].get<unsigned short> () << " + " << ops[1].get<unsigned short> () << " = " << ret << std::endl;
	}
	else {
		//execADD (ops[0].get<unsigned char> (), ops[1].get<unsigned char> ());
		unsigned char ret;
		p->m_alu->opAdd (ops[0].get<unsigned char> (), ops[1].get<unsigned char> (), ret);
		ops[0].get<unsigned char> () = ret;
		//ops[0].get<unsigned char> () += ops[1].get<unsigned char> ();
	}
}

void
ExecutionUnit::execDEC (std::vector<NumberWrapper> &ops) {
	if (ops[0].size () == sizeof(unsigned short)) {
		//execDEC (ops[0].get<unsigned short> ());
		unsigned short ret;
		p->m_alu->opDec (ops[0].get<unsigned short> (), ret);
		ops[0].get<unsigned short> () = ret;
	}
	else {
		//execDEC (ops[0].get<unsigned char> ());
		unsigned char ret;
		p->m_alu->opDec (ops[0].get<unsigned char> (), ret);
		ops[0].get<unsigned char> () = ret;
	}
}

void
ExecutionUnit::execINC (std::vector<NumberWrapper> &ops) {
	if (ops[0].size () == sizeof(unsigned short)) {
		//execINC (ops[0].get<unsigned short> ());
		unsigned short ret;
		p->m_alu->opInc (ops[0].get<unsigned short> (), ret);
		ops[0].get<unsigned short> () = ret;
	}
	else {
		//execINC (ops[0].get<unsigned char> ());
		unsigned char ret;
		p->m_alu->opInc (ops[0].get<unsigned char> (), ret);
		ops[0].get<unsigned char> () = ret;
	}
}

void
ExecutionUnit::execJE (std::vector<NumberWrapper> &ops) {
	if (ops[0].size () == sizeof(short)) {
		//execJE (ops[0].get<short> ());
		p->m_biu->getRegIP () += ops[0].get<short> ();
	}
	else {
		//execJE (ops[0].get<char> ());
		p->m_biu->getRegIP () += ops[0].get<char> ();
	}
}

void
ExecutionUnit::execMOV (std::vector<NumberWrapper> &ops) {
	if (ops[0].size () == sizeof(unsigned short)) {
		//FIXME - debugging
		//std::cout << "execMOV (" << ops[0].get<unsigned short> () << " , " << ops[1].get<unsigned short> () << ")" << std::endl;

		//InstructionExecuter::execMOV (*p->m_cpu, ops[0].get<unsigned short> (), ops[1].get<unsigned short> ());
		ops[0].get<unsigned short> () = ops[1].get<unsigned short> ();
	}
	else {
		//FIXME - debugging
		//std::cout << "execMOV (" << ops[0].get<unsigned char> () << " , " << ops[1].get<unsigned char> () << ")" << std::endl;

		InstructionExecuter::execMOV (*p->m_cpu, ops[0].get<unsigned char> (), ops[1].get<unsigned char> ());
		ops[0].get<unsigned char> () = ops[1].get<unsigned char> ();
	}
}

void
ExecutionUnit::execXCHG (std::vector<NumberWrapper> &ops) {
	if (ops[0].size () == sizeof(unsigned short)) {
		//execXCHG (ops[0].get<unsigned short> (), ops[1].get<unsigned short> ());
		unsigned short tmp = ops[0].get<unsigned short> ();
		ops[0].get<unsigned short> () = ops[1].get<unsigned short> ();
		ops[1].get<unsigned short> () = tmp;
	}
	else {
		//execXCHG (ops[0].get<unsigned char> (), ops[1].get<unsigned char> ());
		unsigned char tmp = ops[0].get<unsigned char> ();
		ops[0].get<unsigned char> () = ops[1].get<unsigned char> ();
		ops[1].get<unsigned char> () = tmp;
	}
}

