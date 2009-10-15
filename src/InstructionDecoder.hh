#ifndef JAF__INSTRUCTION_DECODER_HH
#define JAF__INSTRUCTION_DECODER_HH

//#include "Operand.hh"
#include "ExecutionUnit.hh"
#include "BusInterfaceUnit.hh"
#include "InstructionTable.hh"
#include "Defines.hh"
#include "NumberWrapper.hh"
#include <vector>
#include <map>
#include <string>
#include <utility>

class InstructionDecoder {
	ExecutionUnit *m_eunit;
	BusInterfaceUnit *m_biu;

public:
	std::vector<unsigned char> m_instruction_bytes;

private:
	unsigned char *m_inst_ptr;
	Jaf::ModRM m_modrm;

	std::vector<NumberWrapper> m_operands;

	typedef void (InstructionDecoder::*DecodeFunc) ();
	std::string m_disassembly;

public:

	InstructionDecoder () {
	}

	/**
	*/
	void connectTo (ExecutionUnit &eu);

	/**
	*/
	void connectTo (BusInterfaceUnit &biu);

	/**
	*/
	void getInstruction ();

	/**
	*/
	void nextInstruction ();

	/**
	*/
	const std::string& getDisassembly () const;

protected:

	/**
	*/
	void decodeInstruction ();

public:
	void decodeNone ();
	void decodeRegRM ();
	void decodeAccImm ();
	void decodeSegment ();
	void decodeAcc ();
	void decodeReg ();
	void decodeShort ();
	void decodeSegRM ();
	void decodeAccReg ();
	void decodeAccMem ();
	void decodeRegImm ();
	void decodeIntra ();
	void decodeInter ();
	void decodeXferInd ();
	void decodeRMImm ();
	void decodeAccPort ();
	void decodeRM ();
	void decodeFlags ();
	void decodeRetPop ();
	void decodeType3 ();
	void decodeEscNum ();
	void decodeAccVPort ();
	void decodeAccBase ();
	void decodeIntNum ();
	void decodeString ();
};

#endif //JAF__INSTRUCTION_DECODER_HH

