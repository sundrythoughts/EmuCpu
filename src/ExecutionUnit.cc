#include "ExecutionUnit.hh"
#include "Utility.hh"

void
ExecutionUnit::connectTo (BusInterfaceUnit &biu) {
	m_biu = &biu;

	//FIXME - connect to signals
}

BusInterfaceUnit&
ExecutionUnit::getBusInterfaceUnit () {
	return *m_biu;
}

Register<unsigned char>&
ExecutionUnit::getReg8 (RegisterIndex8 index) {
	return m_regs8[index]; //FIXME - no bounds checking
}

void
ExecutionUnit::setReg8 (RegisterIndex8 index, unsigned char val) {
	m_regs8[index] = val; //FIXME - no bounds checking
}

Register<unsigned short>&
ExecutionUnit::getReg16 (RegisterIndex16 index) {
	return m_regs16[index]; //FIXME - no bounds checking
}

void
ExecutionUnit::setReg16 (RegisterIndex16 index, unsigned short val) {
	m_regs16[index] = val; //FIXME - no bounds checking
}

Register<unsigned short>&
ExecutionUnit::getRegAX () {
	return m_regs16[REG_AX];
}

void
ExecutionUnit::setRegAX (unsigned short val) {
	m_regs16[REG_AX] = val;
}

Register<unsigned char>&
ExecutionUnit::getRegAH () {
	return m_regs8[REG_AH];
}

void
ExecutionUnit::setRegAH (unsigned char val) {
	m_regs8[REG_AH] = val;
}

Register<unsigned char>&
ExecutionUnit::getRegAL () {
	return m_regs8[REG_AL];
}

void
ExecutionUnit::setRegAL (unsigned char val) {
	m_regs8[REG_AL] = val;
}

Register<unsigned short>&
ExecutionUnit::getRegBX () {
	return m_regs16[REG_BX];
}

void
ExecutionUnit::setRegBX (unsigned short val) {
	m_regs16[REG_BX] = val;
}

Register<unsigned char>&
ExecutionUnit::getRegBH () {
	return m_regs8[REG_BH];
}

void
ExecutionUnit::setRegBH (unsigned char val) {
	m_regs8[REG_BH] = val;
}

Register<unsigned char>&
ExecutionUnit::getRegBL () {
	return m_regs8[REG_BL];
}

void
ExecutionUnit::setRegBL (unsigned char val) {
	m_regs8[REG_BL] = val;
}

Register<unsigned short>&
ExecutionUnit::getRegCX () {
	return m_regs16[REG_CX];
}

void
ExecutionUnit::setRegCX (unsigned short val) {
	m_regs16[REG_CX] = val;
}

Register<unsigned char>&
ExecutionUnit::getRegCH () {
	return m_regs8[REG_CH];
}

void
ExecutionUnit::setRegCH (unsigned char val) {
	m_regs8[REG_CH] = val;
}

Register<unsigned char>&
ExecutionUnit::getRegCL () {
	return m_regs8[REG_CL];
}

void
ExecutionUnit::setRegCL (unsigned char val) {
	m_regs8[REG_CL] = val;
}

Register<unsigned short>&
ExecutionUnit::getRegDX () {
	return m_regs16[REG_DX];
}

void
ExecutionUnit::setRegDX (unsigned short val) {
	m_regs16[REG_DX] = val;
}

Register<unsigned char>&
ExecutionUnit::getRegDH () {
	return m_regs8[REG_DH];
}

void
ExecutionUnit::setRegDH (unsigned char val) {
	m_regs8[REG_DH] = val;
}

Register<unsigned char>&
ExecutionUnit::getRegDL () {
	return m_regs8[REG_DL];
}

void
ExecutionUnit::setRegDL (unsigned char val) {
	m_regs8[REG_DL] = val;
}

Register<unsigned short>&
ExecutionUnit::getRegDI () {
	return m_regs16[REG_DI];
}

void
ExecutionUnit::setRegDI (unsigned short val) {
	m_regs16[REG_DI] = val;
}

Register<unsigned short>&
ExecutionUnit::getRegSI () {
	return m_regs16[REG_SI];
}

void
ExecutionUnit::setRegSI (unsigned short val) {
	m_regs16[REG_SI] = val;
}

Register<unsigned short>&
ExecutionUnit::getRegBP () {
	return m_regs16[REG_BP];
}

void
ExecutionUnit::setRegBP (unsigned short val) {
	m_regs16[REG_BP] = val;
}

Register<unsigned short>&
ExecutionUnit::getRegSP () {
	return m_regs16[REG_SP];
}

void
ExecutionUnit::setRegSP (unsigned short val) {
	m_regs16[REG_SP] = val;
}

Register<unsigned short>&
ExecutionUnit::getRegFlags () {
	return m_regs16[REG_FLAGS];
}

void
ExecutionUnit::setRegFlags (unsigned short val) {
	m_regs16[REG_FLAGS] = val;
}

bool
ExecutionUnit::getRegFlagsAF () const {
	return Utility::get_bit (m_regs16[REG_FLAGS], 4);
}

void
ExecutionUnit::setRegFlagsAF (bool val) {
	if (val) {
		Utility::set_bit (m_regs16[REG_FLAGS], 4);
	}
	else {
		Utility::clear_bit (m_regs16[REG_FLAGS], 4);
	}
}

bool
ExecutionUnit::getRegFlagsCF () const {
	return Utility::get_bit (m_regs16[REG_FLAGS], 0);
}

void
ExecutionUnit::setRegFlagsCF (bool val) {
	if (val) {
		Utility::set_bit (m_regs16[REG_FLAGS], 0);
	}
	else {
		Utility::clear_bit (m_regs16[REG_FLAGS], 0);
	}
}

bool
ExecutionUnit::getRegFlagsDF () const {
	return Utility::get_bit (m_regs16[REG_FLAGS], 10);
}

void
ExecutionUnit::setRegFlagsDF (bool val) {
	if (val) {
		Utility::set_bit (m_regs16[REG_FLAGS], 10);
	}
	else {
		Utility::clear_bit (m_regs16[REG_FLAGS], 10);
	}
}

bool
ExecutionUnit::getRegFlagsIF () const {
	return Utility::get_bit (m_regs16[REG_FLAGS], 9);
}

void
ExecutionUnit::setRegFlagsIF (bool val) {
	if (val) {
		Utility::set_bit (m_regs16[REG_FLAGS], 9);
	}
	else {
		Utility::clear_bit (m_regs16[REG_FLAGS], 9);
	}
}

bool
ExecutionUnit::getRegFlagsOF () const {
	return Utility::get_bit (m_regs16[REG_FLAGS], 11);
}

void
ExecutionUnit::setRegFlagsOF (bool val) {
	if (val) {
		Utility::set_bit (m_regs16[REG_FLAGS], 11);
	}
	else {
		Utility::clear_bit (m_regs16[REG_FLAGS], 11);
	}
}

bool
ExecutionUnit::getRegFlagsPF () const {
	return Utility::get_bit (m_regs16[REG_FLAGS], 2);
}

void
ExecutionUnit::setRegFlagsPF (bool val) {
	if (val) {
		Utility::set_bit (m_regs16[REG_FLAGS], 2);
	}
	else {
		Utility::clear_bit (m_regs16[REG_FLAGS], 2);
	}
}

bool
ExecutionUnit::getRegFlagsSF () const {
	return Utility::get_bit (m_regs16[REG_FLAGS], 7);
}

void
ExecutionUnit::setRegFlagsSF (bool val) {
	if (val) {
		Utility::set_bit (m_regs16[REG_FLAGS], 7);
	}
	else {
		Utility::clear_bit (m_regs16[REG_FLAGS], 7);
	}
}

bool
ExecutionUnit::getRegFlagsTF () const {
	return Utility::get_bit (m_regs16[REG_FLAGS], 8);
}

void
ExecutionUnit::setRegFlagsTF (bool val) {
	if (val) {
		Utility::set_bit (m_regs16[REG_FLAGS], 8);
	}
	else {
		Utility::clear_bit (m_regs16[REG_FLAGS], 8);
	}
}

bool
ExecutionUnit::getRegFlagsZF () const {
	return Utility::get_bit (m_regs16[REG_FLAGS], 6);
}

void
ExecutionUnit::setRegFlagsZF (bool val) {
	if (val) {
		Utility::set_bit (m_regs16[REG_FLAGS], 6);
	}
	else {
		Utility::clear_bit (m_regs16[REG_FLAGS], 6);
	}
}

