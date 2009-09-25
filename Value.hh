#ifndef VALUE_HH
#define VALUE_HH

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
	void *_data; //pointer to data
	std::string _type_name; //typeid type name FIXME - might only need a pointer comparison because typeid ().name () returns a {const char*}
	bool _call_free; //free the _data? (Yes/No)
	bool (Value::*free_func) (); //pointer to the correct free<T> () function
	bool (Value::*copy_func) (Value &dest); //pointer to the correct copy<T> () function

public:

	/**
	*/
	Value () : _data (0) {
	}

	/**
	@brief Automaticaly free data if init (true).
	*/
	~Value () {
		if (_call_free) {
			free ();
		}
	}

	/**
	@brief Initialize an instance of Value.
	@param del_data Whether or not to delete data if automatic instances go out of scope.
	@return true if init was successful, false if init was unsuccessful.
	*/
	template<typename T>
	bool init (bool del_data = true) {
		if (_data) {
			std::cerr << "class Value - Unable to initialize a Value that is already initialized." << std::endl;
			return false;
		}

		_data = new T ();
		_type_name = typeid(T).name ();
		_call_free = del_data;
		free_func = &Value::free_template<T>;
		copy_func = &Value::copy_template<T>;
		return true;
	}

	/**
	@brief Get the raw data pointer.
	@return Raw data pointer.
	*/
	const void* get_pointer () {
		return _data;
	}

	/**
	@brief Get the typeid type name string.
	@return Typeid type name string.
	*/
	const std::string& type_name () const {
		return _type_name;
	}

	/**
	@brief Get the data from Value.
	@param v Variable in which to put the data.
	@return true if successful, false if unsuccessful.
	*/
	template<typename T>
	bool get_value (T &v) {
		if (!_data) {
			std::cerr << "class Value - Unable to initialize a Value that is already initialized." << std::endl;
			return false;
		}
		if (0 != std::strcmp (_type_name.c_str (), typeid(T).name ())) {
			std::cerr << "class Value - Trying to use an incompatible type." << std::endl;
			return false;
		}

		T *tmp = (T*)_data;
		v = *tmp;
		return true;
	}

	/**
	@brief Get the data from Value as a pointer.
	@param v Variable in which to put the data pointer.
	@return true if successful, false if unsuccessful.
	*/
	template<typename T>
	bool get_value_pointer (T* &v) {
		if (!_data) {
			std::cerr << "class Value - Unable to initialize a Value that is already initialized." << std::endl;
			return false;
		}
		if (0 != std::strcmp (_type_name.c_str (), typeid(T).name ())) {
			std::cerr << "class Value - Trying to use an incompatible type." << std::endl;
			return false;
		}

		v = (T*)_data;
		return true;
	}

	/**
	@brief Set the data of Value.
	@param v Value to set data to.
	@return true if successful, false if unsuccessful.
	*/
	template<typename T>
	bool set_value (const T &v) const {
		if (!_data) {
			std::cerr << "class Value - Unable to initialize a Value that is already initialized." << std::endl;
			return false;
		}
		if (0 != std::strcmp (_type_name.c_str (), typeid(T).name ())) {
			std::cerr << "class Value - Trying to use an incompatible type." << std::endl;
			return false;
		}

		T *tmp = (T*)_data;
		*tmp = v;

		return true;
	}

	/**
	@brief Free the memory of the data.
	*/
	bool free () {
		return (this->*free_func) ();
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
	bool free_template () {
		if (!_data) {
			std::cerr << "class Value - Unable to initialize a Value that is already initialized." << std::endl;
			return false;
		}
		if (0 != std::strcmp (_type_name.c_str (), typeid(T).name ())) {
			std::cerr << "class Value - Trying to use an incompatible type." << std::endl;
			return false;
		}

		delete (T*)(_data);
		_data = 0;
		_type_name.clear ();
		_call_free = true;
		return true;
	}

	/*
	Copy this into dest.
	*/
	template<typename T>
	bool copy_template (Value &dest) {
		if (!_data || !dest._data) {
			std::cerr << "class Value - Unable to initialize a Value that is already initialized." << std::endl;
			return false;
		}
		if (0 != std::strcmp (_type_name.c_str (), dest._type_name.c_str ())) {
			std::cerr << "class Value - Trying to use an incompatible type." << std::endl;
			return false;
		}

		T *p1, *p2;
		p1 = (T*)_data;
		p2 = (T*)dest._data;

		*p2 = *p1;
		dest._type_name = _type_name;
		_call_free = dest._call_free;
		free_func = dest.free_func;
		copy_func = dest.copy_func;
		return true;
	}

	//private copy constructor
	Value (Value &v);
};

#endif //VALUE_HH

