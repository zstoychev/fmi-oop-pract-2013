#include "UnaryFunctions.h"
#include <cmath>
#include <sstream>
using namespace std;

TrigonometricFunction::TrigonometricFunction(TrigonometricFunctionType type, bool isSignNonNegative)
	: type(type), isSignNonNegative(isSignNonNegative) {
}

double TrigonometricFunction::value(double x) const {
	return (isSignNonNegative ? 1 : -1) * (type == SIN ? sin(x) : cos(x));
}

UnaryFunction* TrigonometricFunction::derivative() const {
	return new TrigonometricFunction(
		type == SIN ? COS : SIN,
		type == SIN ? isSignNonNegative : !isSignNonNegative
	);
}

TrigonometricFunction* TrigonometricFunction::clone() const {
	return new TrigonometricFunction(*this);
}

string TrigonometricFunction::toString(string variable) const {
	ostringstream str;

	str << (isSignNonNegative ? "" : "-") << (type == SIN ? "sin" : "cos") << variable;

	return str.str();
}
