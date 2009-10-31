/**
@file InstructionDecoder.hh
@brief Do all the decoding of instruction addressing modes.
*/

#ifndef JAF__INSTRUCTION_DECODER_HH
#define JAF__INSTRUCTION_DECODER_HH

#include <string>
#include <sigc++/sigc++.h>

class CpuComponents;
class InstructionDecoderPrivate;

/**
@class InstructionDecoder
@brief Do all the decoding of instruction addressing modes.
*/
class InstructionDecoder {
	InstructionDecoderPrivate *p;

public:
	/** */
	InstructionDecoder ();

	/** */
	~InstructionDecoder ();

	/** Create a connection to the CpuComponents */
	void connectTo (CpuComponents &cpu);

	/** Re-decode the current instruction */
	void getInstruction ();

	/** Decode the next instruction */
	void nextInstruction ();

	sigc::signal<void, const std::string&,
	                   const std::string&,
	                   const std::string&,
	                   const std::string&>& signalNextInstruction ();

protected:

#if 0
	template<typename T>
	T getInstructionBytes () {
		unsigned short imm = p->m_biu->getInstructionBytes<unsigned short> ();
		p->m_inst.addBytes (imm);

		return val;
	}
#endif

	/** Do the actual decoding of the next instruction */
	void decodeInstruction ();

public:
	/** */
	void decodeNotImplemented ();

	/** Decode addressing mode None */
	void decodeNone ();

	/** Decode addressing mode RegRM */
	void decodeRegRM ();

	/** Decode addressing mode AccImm */
	void decodeAccImm ();

	/** Decode addressing mode Segment */
	void decodeSegment ();

	/** Decode addressing mode Acc */
	void decodeAcc ();

	/** Decode addressing mode Reg */
	void decodeReg ();

	/** Decode addressing mode Short */
	void decodeShort ();

	/** Decode addressing mode SegRM */
	void decodeSegRM ();

	/** Decode addressing mode AccReg */
	void decodeAccReg ();

	/** Decode addressing mode AccMem */
	void decodeAccMem ();

	/** Decode addressing mode RegImm */
	void decodeRegImm ();

	/** Decode addressing mode Intra */
	void decodeIntra ();

	/** Decode addressing mode Inter */
	void decodeInter ();

	/** Decode addressing mode XferInd */
	void decodeXferInd ();

	/** Decode addressing mode RmImm */
	void decodeRMImm ();

	/** Decode addressing mode AccPort */
	void decodeAccPort ();

	/** Decode addressing mode RM */
	void decodeRM ();

	/** Decode addressing mode Flags */
	void decodeFlags ();

	/** Decode addressing mode RetPop */
	void decodeRetPop ();

	/** Decode addressing mode Type3 */
	void decodeType3 ();

	/** Decode addressing mode EscNum */
	void decodeEscNum ();

	/** Decode addressing mode AccVPort */
	void decodeAccVPort ();

	/** Decode addressing mode AccBase */
	void decodeAccBase ();

	/** Decode addressing mode IntNum */
	void decodeIntNum ();

	/** Decode addressing mode String */
	void decodeString ();

}; //end class InstructionDecoder

#endif //JAF__INSTRUCTION_DECODER_HH

