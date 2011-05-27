/*
 * emucpu -- Emulates processors
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

#ifndef EMUCPU__INSTRUCTION_DECODER_HH
#define EMUCPU__INSTRUCTION_DECODER_HH

#include <sstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <sigc++/sigc++.h>
#include "NumberWrapper.hh"

#include <QtGlobal>

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
		uint16 imm = p->m_biu->getInstructionBytes<uint16> ();
		p->m_inst.addBytes (imm);

		return val;
	}
#endif

	/** @brief Do the actual decoding of the next instruction */
	void decodeInstruction ();

	/** @brief Do the actual decoding of the ModRM byte */
	quint16 decodeRm0To7 (quint8 mrm, std::ostringstream &dis);

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

protected:
	/**
	@brief Get the Instruction source operand.
	*/
	NumberWrapper& instSrc ();

	/**
	@brief Get the Instruction destination operand.
	*/
	NumberWrapper& instDest ();

	/**
	@brief Get the Instruction source operand if b is true, else get destination.
	*/
	NumberWrapper& instSrcIf (bool b);

	/**
	@brief Get the Instruction destination operand if b is true, else get source.
	*/
	NumberWrapper& instDestIf (bool b);

	/**
	@brief Get the disassembly source operand.
	*/
	std::ostringstream& disSrc ();

	/**
	@brief Get the disassembly destination operand.
	*/
	std::ostringstream& disDest ();

	/**
	@brief Get the disassembly source operand if b is true, else get destination.
	*/
	std::ostringstream& disSrcIf (bool b);

	/**
	@brief Get the disassembly destination operand if b is true, else get source.
	*/
	std::ostringstream& disDestIf (bool b);

	/**
	@brief Format the ostream for a 1-byte hex digit with zeros for padding.
	*/
	static std::ostream& formatHexByte (std::ostream& os);

	/**
	@brief Format the ostream for a 2-byte hex digit with zeros for padding.
	*/
	static std::ostream& formatHexWord (std::ostream& os);

}; //end class InstructionDecoder

#endif //EMUCPU__INSTRUCTION_DECODER_HH

