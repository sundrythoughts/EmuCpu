#ifndef JAF__BUS_INTERFACE_UNIT_HH
#define JAF__BUS_INTERFACE_UNIT_HH

#include "Memory.hh"
#include "Register.hh"
#include "MemoryAddress.hh"
#include <vector>
#include <iostream>

class Cpu;
class BusInterfaceUnitPrivate;

/**
*/
class BusInterfaceUnit {
	BusInterfaceUnitPrivate *p;

	unsigned short m_cs;
	unsigned short m_ds;
	unsigned short m_es;
	unsigned short m_ss;
	unsigned short m_ip;
	unsigned short m_seg_override;

	Register<unsigned short> m_sreg_cs;
	Register<unsigned short> m_sreg_ds;
	Register<unsigned short> m_sreg_es;
	Register<unsigned short> m_sreg_ss;
	Register<unsigned short> m_reg_ip;
	Memory *m_memory;

public:
	/** */
	BusInterfaceUnit ();

	/** */
	BusInterfaceUnit (const BusInterfaceUnit &src);

	/** */
	~BusInterfaceUnit ();

	/** */
	void initialize ();

	/** */
	void connectTo (Cpu &cpu);

	/** */
	//Register<unsigned short>& getSegReg (size_t index);

	/** */
	//void setSegReg (size_t index, unsigned short val);

	/** */
	Register<unsigned short>& getSegRegCS ();

	/** */
	void setSegRegCS (unsigned short val);

	/** */
	Register<unsigned short>& getSegRegDS ();

	/** */
	void setSegRegDS (unsigned short val);

	/** */
	Register<unsigned short>& getSegRegES ();

	/** */
	void setSegRegES (unsigned short val);

	/** */
	Register<unsigned short>& getSegRegSS ();

	/** */
	void setSegRegSS (unsigned short val);

	/** */
	Register<unsigned short>& getRegIP ();

	/** */
	void setRegIP (unsigned short val);

	/** */
	void setSegOverride (unsigned short val);

	/** */
	template<typename T>
	void getMemoryAddress (MemoryAddress<T> * &mem_addr, unsigned short seg, unsigned short offset);

	template<typename T>
	T getInstructionBytes () {
		size_t m_phys_addr = m_sreg_cs << 4;
		m_phys_addr += m_reg_ip;
		T val;
		m_memory->read (m_phys_addr, val);

		m_reg_ip += sizeof(T);

		return val;
	}
};

template<typename T>
void
BusInterfaceUnit::getMemoryAddress (MemoryAddress<T> * &mem_addr, unsigned short seg, unsigned short offset) {
	if (m_seg_override != (unsigned short)-1) {
		seg = m_seg_override;
		m_seg_override = (unsigned short)-1;
	}

	mem_addr = new MemoryAddress<T> (m_memory, seg, offset);
}

#endif //JAF__BUS_INTERFACE_UNIT_HH

