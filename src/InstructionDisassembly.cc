#include "InstructionDisassembly.hh"
#include <sstream>
#include <iomanip>

const std::string&
InstructionDisassembly::getSegmentOffset () const {
	return m_seg_off;
}

void
InstructionDisassembly::setSegmentOffset (unsigned short seg, unsigned short off) {
	std::ostringstream oss;
	oss << std::setfill ('0') << std::setw (4) << std::hex << seg;
	oss << ":";
	oss << std::setfill ('0') << std::setw (4) << std::hex << off;

	m_seg_off = oss.str ();
}

const std::string&
InstructionDisassembly::getMachineCode () const {
	return m_machine_code;
}

void
InstructionDisassembly::setMachineCode (const std::vector<unsigned char> &code) {
	std::ostringstream oss;
	for (size_t i = 0; i < code.size (); ++i) {
		oss << std::setfill ('0') << std::setw (2) << std::hex << (size_t)code[i];
	}

	m_machine_code = oss.str ();
}

const std::string&
InstructionDisassembly::getAddressingMode () const {
	return m_addr_mode;
}

void
InstructionDisassembly::setAddressingMode (const std::string &s) {
	m_addr_mode = s;
}

const std::string&
InstructionDisassembly::getAssembly () const {
	return m_assembly;
}

void
InstructionDisassembly::setAssembly (const std::string s) {
	m_assembly = s;
}

void
InstructionDisassembly::clear () {
	m_seg_off.clear ();
	m_machine_code.clear ();
	m_addr_mode.clear ();
	m_assembly.clear ();
}

std::string
InstructionDisassembly::toString () const {
	return m_seg_off + "\t" + m_machine_code + "\t" + m_assembly + "\t" + m_addr_mode;
}

