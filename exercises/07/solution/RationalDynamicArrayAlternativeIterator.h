#ifndef RATIONAL_DYNAMIC_ARRAY_ALTERNATIVE_ITERATOR_H
#define RATIONAL_DYNAMIC_ARRAYALTERNATIVE_ITERATOR_H

#include "Rational.h"

class RatDynamicArrAltIterator {
	Rational* arr;
	int capacity;
	int size;

	void copyArr(const Rational* arr);
	void ensureSpace();

public:
	RatDynamicArrAltIterator();
	explicit RatDynamicArrAltIterator(int capacity);
	RatDynamicArrAltIterator(const RatDynamicArrAltIterator& other);
	~RatDynamicArrAltIterator();
	RatDynamicArrAltIterator operator=(const RatDynamicArrAltIterator& other);

	void push(const Rational& rat);
	void insertAt(int index, const Rational& rat);
	void pop();
	void removeAt(int index);
	Rational& get(int index);
	const Rational& get(int index) const;
	void set(int index, const Rational& rat);
	int getSize() const;

	void swap(RatDynamicArrAltIterator& other);

	Rational& operator [](int index);
	const Rational& operator [](int index) const;

	void operator <<(const Rational& rat);
	void operator >>(Rational& rat);
	void operator <<(const RatDynamicArrAltIterator& other);

	operator bool() const;

	void operator ()(Rational (*f)(const Rational&));

	Rational* begin();
	Rational* end();
};

#endif
