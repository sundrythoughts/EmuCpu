#ifndef I_NUMBER_READABLE_HH
#define I_NUMBER_READABLE_HH

/**
*/
template<typename T>
class INumberReadable {

public:
	/** */
	virtual ~INumberReadable () {
	}

	/** */
	virtual operator const T& () const = 0;

	/** */
	virtual const T& getValue () const = 0;
};

#endif //I_NUMBER_READABLE_HH

