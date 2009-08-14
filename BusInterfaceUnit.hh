#ifndef BUS_INTERFACE_UNIT_HH
#define BUS_INTERFACE_UNIT_HH

#include "Memory.hh"
#include <vector>

class BusInterfaceUnit {
	unsigned short m_sreg_cs;
	unsigned short m_sreg_ds;
	unsigned short m_sreg_es;
	unsigned short m_sreg_ss;
	unsigned short m_reg_ip;

	Memory *m_memory;

public:
	/** */
	BusInterfaceUnit () {
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

	/**
	@brief Read T bytes of data from addr into dest.
	@param seg The memory segment to use.
	@param offset The offset of the memory segment.
	@param dest The destination of the data that is read.
	@return true if successful, false if unsuccessful.
	*/
	template<typename T>
	bool read (unsigned short seg, unsigned short offset, T* &dest) const;

	/**
	@brief Write T bytes of data into addr from src.
	@param seg The memory segment to use.
	@param offset The offset of the memory segment.
	@param src The data that is written.
	@return true if successful, false if unsuccessful.
	*/
	template<typename T>
	bool write (unsigned short seg, unsigned short offset, const T &src);

	/** */
	unsigned short& get_sreg_cs ();

	/** */
	void set_sreg_cs (unsigned short val);

	/** */
	unsigned short& get_sreg_ds ();

	/** */
	void set_sreg_ds (unsigned short val);

	/** */
	unsigned short& get_sreg_es ();

	/** */
	void set_sreg_es (unsigned short val);

	/** */
	unsigned short& get_sreg_ss ();

	/** */
	void set_sreg_ss (unsigned short val);

	/** */
	unsigned short& get_reg_ip ();

	/** */
	void set_reg_ip (unsigned short val);
};

template<typename T>
bool
BusInterfaceUnit::read (unsigned short seg, unsigned short offset, T* &dest) const {
	unsigned int phys_addr = seg << 4;
	phys_addr += offset;

	return m_memory->read (phys_addr, dest);
}

template<typename T>
bool
BusInterfaceUnit::write (unsigned short seg, unsigned short offset, const T &src) {
	unsigned int phys_addr = seg << 4;
	phys_addr += offset;

	return m_memory->write (phys_addr, src);
}

#endif //BUS_INTERFACE_UNIT_HH

