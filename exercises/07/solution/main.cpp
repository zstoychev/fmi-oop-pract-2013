#include <iostream>
#include <algorithm>
#include <functional>
#include "Rational.h"
#include "RationalDynamicArray.h"
using namespace std;

void printRational(const Rational& rat) {
    cout << rat << endl;
}

int main() {
	RationalDynamicArray arr;

	arr << Rational(1, 2);
	arr << Rational(1);
	arr << Rational(10, 20);
	arr << Rational (10, 11);
	arr << Rational(5);
	arr << Rational(-1);
	arr << Rational(2);
	arr << Rational (50, 3);

	typedef RationalDynamicArray::Iterator RatIt;

	cout << "The array (using iterators directly)" << endl;
	for (RatIt i = arr.begin(); i != arr.end(); ++i) {
		printRational(*i);
	}
	cout << "Iterator instances: " << RationalDynamicArray::Iterator::getNumberOfInstances() << endl;
	cout << "Creating iterator..." << endl;
	RatIt it;
	cout << "Iterator instances: " << RationalDynamicArray::Iterator::getNumberOfInstances() << endl;

	// The following functions and constructs are not part of the course
	// and are given just as additional information. Ignore them if you have trouble
	// understanding them.
	cout << "Min element: " << *min_element(arr.begin(), arr.end()) << endl;
	cout << "Max element: " << *max_element(arr.begin(), arr.end()) << endl;

	cout << "The array (for_each with external function):" << endl;
	for_each(arr.begin(), arr.end(), printRational);

	cout << "The array (for_each with method):" << endl;
	for_each(arr.begin(), arr.end(), mem_fun_ref(&Rational::print));
	cout << endl;

	cout << "The array (for_each with lambda):" << endl;
	for_each(arr.begin(), arr.end(), [] (const Rational& rat) {cout << rat << endl;});

	cout << "The array with each element inversed:" << endl;
	transform(arr.begin(), arr.end(), arr.begin(), mem_fun_ref(&Rational::operator~));
	for_each(arr.begin(), arr.end(), printRational);

	cout << "The array (using range-based for loop):" << endl;
	for (const Rational& rat : arr) {
		cout << rat << endl;
	}

	cout << "Iterator instances: " << RationalDynamicArray::Iterator::getNumberOfInstances() << endl;
}
