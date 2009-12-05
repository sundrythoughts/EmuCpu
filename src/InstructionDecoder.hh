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

	/** @brief Create a connection to the CpuComponents. */
	void connectTo (CpuComponents &cpu);

	/** @brief Set the decoder to its default state. */
	void reset ();

	/** @brief Re-decode the current instruction */
	void getInstruction ();

	/** @brief Decode the next instruction */
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

	/** @brief Do the actual decoding of the next instruction */
	void decodeInstruction ();

	//FIXME
	void decodeRm0To7 ();

public:
	/** */
	void decodeNotImplemented ();

	/** @brief Decode addressing mode None */
	void decodeNone ();

	/** @brief Decode addressing mode RegRM */
	void decodeRegRM ();

	/** @brief Decode addressing mode AccImm */
	void decodeAccImm ();

	/** @brief Decode addressing mode Segment */
	void decodeSegment ();

	/** @brief Decode addressing mode Acc */
	void decodeAcc ();

	/** @brief Decode addressing mode Reg */
	void decodeReg ();

	/** @brief Decode addressing mode Short */
	void decodeShort ();

	/** @brief Decode addressing mode SegRM */
	void decodeSegRM ();

	/** @brief Decode addressing mode AccReg */
	void decodeAccReg ();

	/** @brief Decode addressing mode AccMem */
	void decodeAccMem ();

	/** @brief Decode addressing mode RegImm */
	void decodeRegImm ();

	/** @brief Decode addressing mode Intra */
	void decodeIntra ();

	/** @brief Decode addressing mode Inter */
	void decodeInter ();

	/** @brief Decode addressing mode XferInd */
	void decodeXferInd ();

	/** @brief Decode addressing mode RmImm */
	void decodeRMImm ();

	/** @brief Decode addressing mode AccPort */
	void decodeAccPort ();

	/** @brief Decode addressing mode RM */
	void decodeRM ();

	/** @brief Decode addressing mode Flags */
	void decodeFlags ();

	/** @brief Decode addressing mode RetPop */
	void decodeRetPop ();

	/** @brief Decode addressing mode Type3 */
	void decodeType3 ();

	/** @brief Decode addressing mode EscNum */
	void decodeEscNum ();

	/** @brief Decode addressing mode AccVPort */
	void decodeAccVPort ();

	/** @brief Decode addressing mode AccBase */
	void decodeAccBase ();

	/** @brief Decode addressing mode IntNum */
	void decodeIntNum ();

	/** @brief Decode addressing mode String */
	void decodeString ();

}; //end class InstructionDecoder

#endif //JAF__INSTRUCTION_DECODER_HH

