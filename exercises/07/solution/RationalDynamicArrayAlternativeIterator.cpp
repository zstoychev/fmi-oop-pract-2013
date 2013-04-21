#include <algorithm>
#include <cassert>
#include "RationalDynamicArrayAlternativeIterator.h"

void RatDynamicArrAltIterator::copyArr(const Rational* arr) {
	this->arr = new Rational[capacity];

	for (int i = 0; i < size; i++) {
		this->arr[i] = arr[i];
	}
}

void RatDynamicArrAltIterator::ensureSpace() {
	if (size == capacity) {
		Rational* oldArr = arr;
		capacity *= 2;
		copyArr(oldArr);
		delete[] oldArr;
	}
}

RatDynamicArrAltIterator::RatDynamicArrAltIterator()
	: capacity(4), size(0) {
	arr = new Rational[capacity];
}

RatDynamicArrAltIterator::RatDynamicArrAltIterator(int capacity)
	: capacity(capacity), size(0) {
	arr = new Rational[capacity];
}

RatDynamicArrAltIterator::RatDynamicArrAltIterator(const RatDynamicArrAltIterator& other)
	: capacity(other.capacity), size(other.size) {
	copyArr(other.arr);
}

RatDynamicArrAltIterator::~RatDynamicArrAltIterator() {
	delete[] arr;
}

void RatDynamicArrAltIterator::swap(RatDynamicArrAltIterator& other) {
	std::swap(arr, other.arr);
	std::swap(capacity, other.capacity);
	std::swap(size, other.size);
}

RatDynamicArrAltIterator RatDynamicArrAltIterator::operator=(const RatDynamicArrAltIterator& other) {
	if (this != &other) {
		RatDynamicArrAltIterator temp(other);
		swap(temp);
	}

	return *this;
}

void RatDynamicArrAltIterator::push(const Rational& rat) {
	insertAt(size, rat);
}

void RatDynamicArrAltIterator::insertAt(int index, const Rational& rat) {
	assert(index >= 0 && index <= size);
	ensureSpace();

	for (int i = size - 1; i >= index; i--) {
		arr[i + 1] = arr[i];
	}

	arr[index] = rat;
	size++;
}

void RatDynamicArrAltIterator::pop() {
	assert(size != 0);

	removeAt(size - 1);
}

void RatDynamicArrAltIterator::removeAt(int index) {
	assert(size > 0);

	size--;
	for (int i = index; i < size; i++) {
		arr[i] = arr[i + 1];
	}
}

Rational& RatDynamicArrAltIterator::get(int index) {
	assert(index >= 0 && index < size);

	return arr[index];
}

const Rational& RatDynamicArrAltIterator::get(int index) const {
	assert(index >= 0 && index < size);

	return arr[index];
}

void RatDynamicArrAltIterator::set(int index, const Rational& rat) {
	assert(index >= 0 && index < size);

	arr[index] = rat;
}

int RatDynamicArrAltIterator::getSize() const {
	return size;
}

Rational& RatDynamicArrAltIterator::operator [](int index) {
	return get(index);
}

const Rational& RatDynamicArrAltIterator::operator [](int index) const {
	return get(index);
}

void RatDynamicArrAltIterator::operator <<(const Rational& rat) {
	push(rat);
}

void RatDynamicArrAltIterator::operator >>(Rational& rat) {
	assert(size != 0);

	rat = (*this)[size - 1];
	pop();
}

void RatDynamicArrAltIterator::operator <<(const RatDynamicArrAltIterator& other) {
	for (int i = 0; i < other.getSize(); i++) {
		*this << other[i];
	}
}

RatDynamicArrAltIterator::operator bool() const {
	return size != 0;
}

void RatDynamicArrAltIterator::operator ()(Rational (*f)(const Rational&)) {
	for (int i = 0; i < size; i++) {
		arr[i] = f(arr[i]);
	}
}

Rational* RatDynamicArrAltIterator::begin() {
	return arr;
}

Rational* RatDynamicArrAltIterator::end() {
	return arr + size;
}
