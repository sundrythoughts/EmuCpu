/**
@file InstructionDisassembly.hh
@brief Store the disassembly of the instruction.
*/

#ifndef JAF__INSTRUCTION_DISASSEMBLY_HH
#define JAF__INSTRUCTION_DISASSEMBLY_HH

#include <string>
#include <vector>
//#include <iostream>

/**
@class InstructionDisassembly
@brief Store the disassembly of the instruction.
*/
class InstructionDisassembly {
	std::string m_seg_off;
	std::string m_machine_code;
	std::string m_addr_mode;
	std::string m_assembly;

public:
	/** */
	const std::string& getSegmentOffset () const;

	/** */
	void setSegmentOffset (unsigned short seg, unsigned short off);

	/** */
	const std::string& getMachineCode () const;

	/** */
	void setMachineCode (const std::vector<unsigned char> &code);

	/** */
	const std::string& getAddressingMode () const;

	/** */
	void setAddressingMode (const std::string &s);

	/** */
	const std::string& getAssembly () const;

	/** */
	void setAssembly (const std::string s);

	/** */
	void clear ();

	std::string toString () const;

}; //end class InstructionDisassembly

#endif //JAF__INSTRUCTION_DISASSEMBLY_HH

