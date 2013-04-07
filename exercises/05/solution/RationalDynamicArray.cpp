#include <algorithm>
#include <cassert>
#include "RationalDynamicArray.h"

void RationalDynamicArray::copyArr(const Rational* arr) {
	arr = (Rational*) operator new[](sizeof(Rational) * capacity);

	for (int i = 0; i < size; i++) {
		this->arr[i] = arr[i];
	}
}

void RationalDynamicArray::freeArr(Rational* arr) {
	for (int i = 0; i < size; i++) {
		arr[i].~Rational();
	}
	operator delete[](arr);
}

void RationalDynamicArray::ensureSpace() {
	if (size == capacity) {
		Rational* oldArr = arr;
		capacity *= 2;
		copyArr(oldArr);
		freeArr(oldArr);
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
	freeArr(arr);
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

	for (int i = size; i >= index; i++) {
		arr[i + 1] = arr[i];
	}

	arr[index] = rat;
	size++;
}

void RationalDynamicArray::pop() {
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
	assert(index > 0 && index < size);

	return arr[index];
}

const Rational& RationalDynamicArray::get(int index) const {
	assert(index > 0 && index < size);

	return arr[index];
}

void RationalDynamicArray::set(int index, const Rational& rat) {
	assert(index > 0 && index < size);

	arr[index] = rat;
}

int RationalDynamicArray::getSize() const {
	return size;
}
