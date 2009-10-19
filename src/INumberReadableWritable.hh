/**
@file INumberReadableWritable.hh
@brief Interface for Immediate, Register, and MemoryAddress.
*/

#ifndef JAF__I_NUMBER_READABLE_WRITABLE_HH
#define JAF__I_NUMBER_READABLE_WRITABLE_HH


/**
@class INumberReadableWritable
@brief Interface for Immediate, Register, and MemoryAddress.
*/
template<typename T>
class INumberReadableWritable {

public:
	/** */
	virtual ~INumberReadableWritable () {
	}

	/** Implicit cast to stored value */
	virtual operator const T& () const = 0;

	/** Get the stored value */
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
	virtual INumberReadableWritable<T>& operator= (const T &right) = 0;

	/** */
	virtual INumberReadableWritable<T>& operator= (const INumberReadableWritable<T> &right) = 0;

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

}; //end class INumberReadableWritable

#endif //JAF__I_NUMBER_READABLE_WRITABLE_HH

