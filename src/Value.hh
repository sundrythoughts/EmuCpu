#ifndef JAF__VALUE_HH
#define JAF__VALUE_HH

#include <typeinfo>
#include <string>
#include <cstring>
#include <iostream>

/**
@class Value
@brief Store and retrieve any data type with no casting required.
Memory management works if the Value is not storing a pointer.
Memory management can also be manual if init(false) is called.
*/
class Value {
	void *m_data; //pointer to data
	std::string m_type_name; //typeid type name FIXME - might only need a pointer comparison because typeid ().name () returns a {const char*}
	bool m_call_free; //free the m_data? (Yes/No)
	bool m_call_free_pointer; //free the pointer stored in m_data (Yes/No)
	bool (Value::*free_func) (); //pointer to the correct free<T> () function
	bool (Value::*free_pointer_func) (); //pointer to the correct free<T> () function
	bool (Value::*copy_func) (Value &dest); //pointer to the correct copy<T> () function
	bool (Value::*copy_pointer_func) (Value &dest); //pointer to the correct copy<T> () function

public:

	/**
	*/
	Value () : m_data (0), m_call_free (false) {
	}

	/**
	@brief Automaticaly free data if init (true).
	*/
	~Value () {
		if (m_call_free) {
			free ();
		}
	}

	/**
	@brief Initialize an instance of Value.
	@param del_data Whether or not to delete data if automatic instances go out of scope.
	@return true if init was successful, false if init was unsuccessful.
	*/
	template<typename T>
	bool init (bool del_ptr_data = false, bool del_data = true) {
		if (m_data) {
			std::cerr << "class Value - Unable to initialize a Value that is already initialized." << std::endl;
			return false;
		}

		m_data = new T ();
		m_type_name = typeid(T).name ();
		m_call_free = del_data;
		m_call_free_pointer = del_ptr_data;
		free_func = &Value::freeTemplate<T>;
		free_pointer_func = &Value::freePointerTemplate<T*>;
		copy_func = &Value::copyTemplate<T>;
		//FIXME - need a copy function
		return true;
	}

	/**
	@brief Get the raw data pointer.
	@return Raw data pointer.
	*/
	const void* getPointer () {
		return m_data;
	}

	/**
	@brief Get the typeid type name string.
	@return Typeid type name string.
	*/
	const std::string& typeName () const {
		return m_type_name;
	}

	/**
	@brief Get the data from Value.
	@param v Variable in which to put the data.
	@return true if successful, false if unsuccessful.
	*/
	template<typename T>
	bool getValue (T &v) {
		if (!m_data) {
			std::cerr << "class Value - Unable to initialize a Value that is already initialized." << std::endl;
			return false;
		}
		if (0 != std::strcmp (m_type_name.c_str (), typeid(T).name ())) {
			std::cerr << "class Value - Trying to use an incompatible type." << std::endl;
			return false;
		}

		T *tmp = (T*)m_data;
		v = *tmp;
		return true;
	}

	/**
	@brief Get the data from Value as a pointer.
	@param v Variable in which to put the data pointer.
	@return true if successful, false if unsuccessful.
	*/
	template<typename T>
	bool getValuePointer (T* &v) {
		if (!m_data) {
			std::cerr << "class Value - Unable to initialize a Value that is already initialized." << std::endl;
			return false;
		}
		if (0 != std::strcmp (m_type_name.c_str (), typeid(T).name ())) {
			std::cerr << "class Value - Trying to use an incompatible type." << std::endl;
			return false;
		}

		v = (T*)m_data;
		return true;
	}

	/**
	@brief Set the data of Value.
	@param v Value to set data to.
	@return true if successful, false if unsuccessful.
	*/
	template<typename T>
	bool setValue (const T &v) const {
		if (!m_data) {
			std::cerr << "class Value - Unable to initialize a Value that is not initialized." << std::endl;
			return false;
		}
		if (0 != std::strcmp (m_type_name.c_str (), typeid(T).name ())) {
			std::cerr << "class Value - Trying to use an incompatible type." << std::endl;
			return false;
		}

		T *tmp = (T*)m_data;
		*tmp = v;

		return true;
	}

	/**
	@brief Free the memory of the data.
	*/
	bool free () {
		bool ret = true;
		if (m_call_free_pointer) {
			ret = (this->*free_pointer_func) ();
		}
		ret &= (this->*free_func) ();
		return ret;
	}

	/**
	@brief Copy this into dest.
	@param dest The destination to copy into.
	*/
	bool copy (Value &dest) {
		return (this->*copy_func) (dest);
	}

private:
	/*
	Free the memory of the data.
	*/
	template<typename T>
	bool freeTemplate () {
		if (!m_data) {
			std::cerr << "class Value - Unable to free a Value that is already uninitialized." << std::endl;
			return false;
		}
		if (0 != std::strcmp (m_type_name.c_str (), typeid(T).name ())) {
			std::cerr << "class Value - Trying to use an incompatible type." << std::endl;
			return false;
		}

		delete (T*)(m_data);
		m_data = 0;
		m_type_name.clear ();
		m_call_free = true;
		return true;
	}

	/*
	Free the memory of the data.
	*/
	template<typename T>
	bool freePointerTemplate () {
		if (!m_data) {
			std::cerr << "class Value - Unable to free a pointer Value that is not initialized." << std::endl;
			return false;
		}
		//if (0 != std::strcmp (m_type_name.c_str (), typeid(T).name ())) {
		//	std::cerr << "class Value - Trying to use an incompatible type." << std::endl;
		//	return false;
		//}

		delete *((T*)(m_data));

		return true;
	}

	/*
	Copy this into dest.
	*/
	template<typename T>
	bool copyTemplate (Value &dest) {
		if (!m_data || !dest.m_data) {
			std::cerr << "class Value - Unable to copy a Value that is not initialized." << std::endl;
			return false;
		}
		if (0 != std::strcmp (m_type_name.c_str (), dest.m_type_name.c_str ())) {
			std::cerr << "class Value - Trying to use an incompatible type." << std::endl;
			return false;
		}

		T *p1, *p2;
		p1 = (T*)m_data;
		p2 = (T*)dest.m_data;

		*p2 = *p1;
		dest.m_type_name = m_type_name;
		m_call_free = dest.m_call_free;
		free_func = dest.free_func;
		copy_func = dest.copy_func;
		return true;
	}

	//private copy constructor
public:
	Value (const Value &v) {
		m_data = 0;
		m_type_name = "";
		m_call_free = false;
		m_call_free_pointer = false;
	}
};

#endif //JAF__VALUE_HH

