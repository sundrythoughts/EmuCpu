/*
 * sim8086 -- Emulates an Intel 8086 processor
 * Copyright (C) 2009  Joseph Freeman (jfree143dev AT gmail DOT com)
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


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

	/** */
	void reset ();

	/** Re-decode the current instruction */
	void getInstruction ();

	/** Decode the next instruction */
	void nextInstruction ();

	/** */
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

	//FIXME
	void decodeRm0To7 ();

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

