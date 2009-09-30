#ifndef I_NUMBER_WRITABLE_HH
#define I_NUMBER_WRITABLE_HH


/**
*/
template<typename T>
class INumberWritable {

public:
	/** */
	virtual ~INumberWritable () {
	}

	/** */
	virtual const INumberWritable<T>& operator++ () = 0;

	/** */
	virtual const T operator++ (int) = 0;

	/** */
	virtual const INumberWritable<T>& operator-- () = 0;

	/** */
	virtual const T operator-- (int) = 0;

	/** */
	virtual INumberWritable<T>& operator= (const T &rhs) = 0;

	/** */
	virtual INumberWritable<T>& operator+= (const T& right) = 0;

	/** */
	virtual INumberWritable<T>& operator-= (const T& right) = 0;

	/** */
	virtual INumberWritable<T>& operator*= (const T& right) = 0;

	/** */
	virtual INumberWritable<T>& operator/= (const T& right) = 0;

	/** */
	virtual INumberWritable<T>& operator%= (const T& right) = 0;

	/** */
	virtual INumberWritable<T>& operator^= (const T& right) = 0;

	/** */
	virtual INumberWritable<T>& operator&= (const T& right) = 0;

	/** */
	virtual INumberWritable<T>& operator|= (const T& right) = 0;

	/** */
	virtual INumberWritable<T>& operator>>= (const T& right) = 0;

	/** */
	virtual INumberWritable<T>& operator<<= (const T& right) = 0;
};

#endif //I_NUMBER_WRITABLE_HH

