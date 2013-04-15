#include <algorithm>
#include <cassert>
#include "RationalDynamicArray.h"

void RationalDynamicArray::copyArr(const Rational* arr) {
	this->arr = new Rational[capacity];

	for (int i = 0; i < size; i++) {
		this->arr[i] = arr[i];
	}
}

void RationalDynamicArray::ensureSpace() {
	if (size == capacity) {
		Rational* oldArr = arr;
		capacity *= 2;
		copyArr(oldArr);
		delete[] oldArr;
	}
}

RationalDynamicArray::RationalDynamicArray()
	: capacity(4), size(0) {
	arr = new Rational[capacity];
}

RationalDynamicArray::RationalDynamicArray(const RationalDynamicArray& other)
	: capacity(other.capacity), size(other.size) {
	copyArr(other.arr);
}

RationalDynamicArray::~RationalDynamicArray() {
	delete[] arr;
}

void RationalDynamicArray::swap(RationalDynamicArray& other) {
	std::swap(arr, other.arr);
	std::swap(capacity, other.capacity);
	std::swap(size, other.size);
}

RationalDynamicArray RationalDynamicArray::operator=(const RationalDynamicArray& other) {
	if (this != &other) {
		RationalDynamicArray temp(other);
		swap(temp);
	}

	return *this;
}

void RationalDynamicArray::push(const Rational& rat) {
	insertAt(size, rat);
}

void RationalDynamicArray::insertAt(int index, const Rational& rat) {
	assert(index >= 0 && index <= size);
	ensureSpace();

	for (int i = size - 1; i >= index; i--) {
		arr[i + 1] = arr[i];
	}

	arr[index] = rat;
	size++;
}

void RationalDynamicArray::pop() {
	assert(size != 0);

	removeAt(size - 1);
}

void RationalDynamicArray::removeAt(int index) {
	assert(size > 0);

	size--;
	for (int i = index; i < size; i++) {
		arr[i] = arr[i + 1];
	}
}

Rational& RationalDynamicArray::get(int index) {
	assert(index >= 0 && index < size);

	return arr[index];
}

const Rational& RationalDynamicArray::get(int index) const {
	assert(index >= 0 && index < size);

	return arr[index];
}

void RationalDynamicArray::set(int index, const Rational& rat) {
	assert(index >= 0 && index < size);

	arr[index] = rat;
}

int RationalDynamicArray::getSize() const {
	return size;
}

Rational& RationalDynamicArray::operator [](int index) {
	return get(index);
}

const Rational& RationalDynamicArray::operator [](int index) const {
	return get(index);
}

void RationalDynamicArray::operator <<(const Rational& rat) {
	push(rat);
}

void RationalDynamicArray::operator >>(Rational& rat) {
	assert(size != 0);

	rat = (*this)[size - 1];
	pop();
}

void RationalDynamicArray::operator <<(const RationalDynamicArray& other) {
	for (int i = 0; i < other.getSize(); i++) {
		*this << other[i];
	}
}

RationalDynamicArray::operator bool() const {
	return size != 0;
}

void RationalDynamicArray::operator ()(Rational (*f)(const Rational&)) {
	for (int i = 0; i < size; i++) {
		arr[i] = f(arr[i]);
	}
}