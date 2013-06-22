#include "UnaryFunctions.h"
#include <algorithm>
#include <sstream>
using namespace std;

LinearCombination::LinearCombination(double coef1, const UnaryFunction& func1, double coef2, const UnaryFunction& func2)
	: coef1(coef1), func1(func1.clone()), coef2(coef2), func2(func2.clone()) {
}

LinearCombination::LinearCombination(const LinearCombination& lc2)
	: coef1(lc2.coef1), func1(lc2.func1->clone()), coef2(lc2.coef2), func2(lc2.func2->clone()){
}

LinearCombination::~LinearCombination() {
	delete func1;
	delete func2;
}

void LinearCombination::swap(LinearCombination& lc2) {
	std::swap(coef1, lc2.coef1);
	std::swap(func1, lc2.func1);
	std::swap(coef2, lc2.coef2);
	std::swap(func2, lc2.func2);
}

LinearCombination& LinearCombination::operator=(const LinearCombination& lc2) {
	if (this != &lc2) {
		LinearCombination temp(lc2);
		swap(temp);
	}

	return *this;
}

double LinearCombination::value(double x) const {
	return coef1 * func1->value(x) + coef2 * func2->value(x);
}

UnaryFunction* LinearCombination::derivative() const {
	UnaryFunction* func1Der = func1->derivative();
	UnaryFunction* func2Der = func2->derivative();

	UnaryFunction* result = new LinearCombination(coef1, *func1Der, coef2, *func2Der);

	delete func1Der;
	delete func2Der;

	return result;
}

LinearCombination* LinearCombination::clone() const {
	return new LinearCombination(*this);
}

string LinearCombination::toString(string variable) const {
	ostringstream str;

	if (coef1 != 0.0) {
		str << coef1 << "*(" << func1->toString(variable) << ")";
	}
	if (coef1 != 0.0 && coef2 != 0.0) {
		str << " + ";
	}
	if (coef2 != 0.0) {
		str << coef2 << "*(" << func2->toString(variable) << ")";
	}

	return str.str();
}
