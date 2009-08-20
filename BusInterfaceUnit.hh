#ifndef BUS_INTERFACE_UNIT_HH
#define BUS_INTERFACE_UNIT_HH

#include "Memory.hh"
#include "Number.hh"
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

	Number<unsigned short> m_sreg_cs;
	Number<unsigned short> m_sreg_ds;
	Number<unsigned short> m_sreg_es;
	Number<unsigned short> m_sreg_ss;
	Number<unsigned short> m_reg_ip;

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
	void connect_to (Memory &mem);

	/** */
	Number<unsigned short>& get_sreg_cs ();

	/** */
	void set_sreg_cs (unsigned short val);

	/** */
	Number<unsigned short>& get_sreg_ds ();

	/** */
	void set_sreg_ds (unsigned short val);

	/** */
	Number<unsigned short>& get_sreg_es ();

	/** */
	void set_sreg_es (unsigned short val);

	/** */
	Number<unsigned short>& get_sreg_ss ();

	/** */
	void set_sreg_ss (unsigned short val);

	/** */
	Number<unsigned short>& get_reg_ip ();

	/** */
	void set_reg_ip (unsigned short val);

	/** */
	void set_seg_override (unsigned short val);

	/** */
	MemoryAddress* get_memory_address (unsigned short seg, unsigned short offset);
};

#endif //BUS_INTERFACE_UNIT_HH

