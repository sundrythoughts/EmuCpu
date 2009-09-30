#ifndef I_NUMBER_READABLE_WRITABLE_HH
#define I_NUMBER_READABLE_WRITABLE_HH

#include "INumberReadable.hh"
#include "INumberWritable.hh"

/**
*/
template<typename T>
class INumberReadableWritable {

public:
	/** */
	virtual ~INumberReadableWritable () {
	}

//#if 0
	/** */
	virtual operator const T& () const = 0;

	/** */
	virtual const T& getValue () const = 0;

	/** */
	virtual const INumberReadableWritable<T>& operator++ () = 0;

	/** */
	virtual const T operator++ (int) = 0;

	/** */
	virtual const INumberReadableWritable<T>& operator-- () = 0;

	/** */
	virtual const T operator-- (int) = 0;

	/** */
	virtual INumberReadableWritable<T>& operator= (const T &rhs) = 0;

	/** */
	virtual INumberReadableWritable<T>& operator+= (const T& right) = 0;

	/** */
	virtual INumberReadableWritable<T>& operator-= (const T& right) = 0;

	/** */
	virtual INumberReadableWritable<T>& operator*= (const T& right) = 0;

	/** */
	virtual INumberReadableWritable<T>& operator/= (const T& right) = 0;

	/** */
	virtual INumberReadableWritable<T>& operator%= (const T& right) = 0;

	/** */
	virtual INumberReadableWritable<T>& operator^= (const T& right) = 0;

	/** */
	virtual INumberReadableWritable<T>& operator&= (const T& right) = 0;

	/** */
	virtual INumberReadableWritable<T>& operator|= (const T& right) = 0;

	/** */
	virtual INumberReadableWritable<T>& operator>>= (const T& right) = 0;

	/** */
	virtual INumberReadableWritable<T>& operator<<= (const T& right) = 0;
//#endif
};

#endif //I_NUMBER_READABLE_WRITABLE_HH

