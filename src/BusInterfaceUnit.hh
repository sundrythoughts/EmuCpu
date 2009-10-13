#ifndef JAF__BUS_INTERFACE_UNIT_HH
#define JAF__BUS_INTERFACE_UNIT_HH

#include "Memory.hh"
#include "Register.hh"
#include "MemoryAddress.hh"
#include <vector>
#include <iostream>

/**
*/
class BusInterfaceUnit {
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
	BusInterfaceUnit () : m_cs (0), m_ds (0), m_es (0), m_ss (0), m_ip (0), m_seg_override (-1),
	                      m_sreg_cs (m_cs), m_sreg_ds (m_ds),
	                      m_sreg_es (m_es), m_sreg_ss (m_ss),
	                      m_reg_ip (m_ip), m_memory (0)
	{
	}

	/** */
	BusInterfaceUnit (const BusInterfaceUnit &src);

	/** */
	~BusInterfaceUnit () {
	}

	/** */
	void initialize ();

	/** */
	void connectTo (Memory &mem);

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

