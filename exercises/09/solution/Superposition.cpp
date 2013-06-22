#include "UnaryFunctions.h"
#include <algorithm>
using namespace std;

Superposition::Superposition(const UnaryFunction& outerFunc, const UnaryFunction& innerFunc)
	: outerFunc(outerFunc.clone()), innerFunc(innerFunc.clone()) {
}

Superposition::Superposition(const Superposition& s2)
	: outerFunc(s2.outerFunc->clone()), innerFunc(s2.innerFunc->clone()){
}

Superposition::~Superposition() {
	delete outerFunc;
	delete innerFunc;
}

void Superposition::swap(Superposition& s2) {
	std::swap(outerFunc, s2.outerFunc);
	std::swap(innerFunc, s2.innerFunc);
}

Superposition& Superposition::operator=(const Superposition& s2) {
	if (this != &s2) {
		Superposition temp(s2);
		swap(temp);
	}

	return *this;
}

double Superposition::value(double x) const {
	return outerFunc->value(innerFunc->value(x));
}

UnaryFunction* Superposition::derivative() const {
	UnaryFunction* outerFuncDer = outerFunc->derivative();
	UnaryFunction* innerFuncDer = innerFunc->derivative();

	UnaryFunction* result = new Product(Superposition(*outerFuncDer, *innerFunc), *innerFuncDer);

	delete outerFuncDer;
	delete innerFuncDer;

	return result;
}

Superposition* Superposition::clone() const {
	return new Superposition(*this);
}

string Superposition::toString(string variable) const {
	return outerFunc->toString("(" + innerFunc->toString() + ")");
}
