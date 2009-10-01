#include "Cpu.hh"

GeneralRegisterSignalsAndSlots&
Cpu::getGeneralRegisterSignalsAndSlots () {
	return m_gen_reg_s_s;
}

FlagRegisterSignalsAndSlots&
Cpu::getFlagRegisterSignalsAndSlots () {
	return m_flag_reg_s_s;
}

SegmentRegisterSignalsAndSlots&
Cpu::getSegmentRegisterSignalsAndSlots () {
	return m_sreg_s_s;
}

MemorySignalsAndSlots&
Cpu::getMemorySignalsAndSlots () {
	return m_mem_s_s;
}

