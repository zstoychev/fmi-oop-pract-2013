#include "UnaryFunctions.h"
#include <algorithm>
#include <sstream>
using namespace std;

Product::Product(const UnaryFunction& func1, const UnaryFunction& func2)
	: func1(func1.clone()), func2(func2.clone()) {
}

Product::Product(const Product& p2)
	: func1(p2.func1->clone()), func2(p2.func2->clone()){
}

Product::~Product() {
	delete func1;
	delete func2;
}

void Product::swap(Product& p2) {
	std::swap(func1, p2.func1);
	std::swap(func2, p2.func2);
}

Product& Product::operator=(const Product& p2) {
	if (this != &p2) {
		Product temp(p2);
		swap(temp);
	}

	return *this;
}

double Product::value(double x) const {
	return func1->value(x) * func2->value(x);
}

UnaryFunction* Product::derivative() const {
	UnaryFunction* func1Der = func1->derivative();
	UnaryFunction* func2Der = func2->derivative();

	UnaryFunction* result = new LinearCombination(1.0, Product(*func1Der, *func2), 1.0, Product(*func1, *func2Der));

	delete func1Der;
	delete func2Der;

	return result;
}

Product* Product::clone() const {
	return new Product(*this);
}

string Product::toString(string variable) const {
	ostringstream str;

	str << "(" << func1->toString(variable) << ") * (" << func2->toString(variable) << ")";

	return str.str();
}
