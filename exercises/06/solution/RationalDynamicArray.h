#ifndef RATIONAL_DYNAMIC_ARRAY_H
#define RATIONAL_DYNAMIC_ARRAY_H

#include "Rational.h"

class RationalDynamicArray {
	Rational* arr;
	int capacity;
	int size;

	void copyArr(const Rational* arr);
	void ensureSpace();

public:
	RationalDynamicArray();
	explicit RationalDynamicArray(int capacity);
	RationalDynamicArray(const RationalDynamicArray& other);
	~RationalDynamicArray();
	RationalDynamicArray operator=(const RationalDynamicArray& other);

	void push(const Rational& rat);
	void insertAt(int index, const Rational& rat);
	void pop();
	void removeAt(int index);
	Rational& get(int index);
	const Rational& get(int index) const;
	void set(int index, const Rational& rat);
	int getSize() const;

	void swap(RationalDynamicArray& other);

	Rational& operator [](int index);
	const Rational& operator [](int index) const;

	void operator <<(const Rational& rat);
	void operator >>(Rational& rat);
	void operator <<(const RationalDynamicArray& other);

	operator bool() const;

	void operator ()(Rational (*f)(const Rational&));
};

#endif
