#ifndef STORAGE_UNIT_HH
#define STORAGE_UNIT_HH

#include <iostream>
#include <vector>

class StorageUnit {
	std::vector<unsigned char> m_storage;

	void read (unsigned char *dest, size_t index, size_t len) {
		for (size_t i = 0; i < len; ++i) {
			dest[index + i] = m_storage[i];
		}
	}

	void write (const unsigned char *src, size_t index, size_t len) {
		for (size_t i = 0; i < len; ++i) {
			m_storage[index + i] = src[i];
		}
	}

public:
	StorageUnit (size_t len) : m_storage (len, 0) {
	}

	size_t size () const {
		return m_storage.size ();
	}

	template<typename T>
	bool read (T &dest, size_t index = 0) {
		if (index + sizeof(T) >= m_storage.size ()) {
			return false;
		}

		read ((unsigned char*)&dest, index, sizeof(T));

		return true;
	}

	template<typename T>
	bool write (const T &src, size_t index = 0) {
		if (index + sizeof(T) >= m_storage.size ()) {
			return false;
		}

		write ((const unsigned char*)&src, index, sizeof(T));

		return true;
	}

	void debugPrint (std::ostream &os) {
		for (unsigned int i = 0; i < m_storage.size (); ++i) {
			os << (unsigned int)m_storage[i] << std::endl;
		}
	}
};

#endif //STORAGE_UNIT_HH

