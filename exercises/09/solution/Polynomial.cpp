#include <sstream>
#include <algorithm>
#include "UnaryFunctions.h"
using namespace std;

Polynomial::Polynomial() {
	coefs = new double[1];
	coefs[0] = 0;
	deg = 0;
}

Polynomial::Polynomial(const double* coefs, int deg) {
	while (coefs[deg] == 0 && deg > 0) {
		deg--;
	}
	init(coefs, deg);
}

Polynomial::Polynomial(const Polynomial& p2) {
	init(p2.coefs, p2.deg);
}

Polynomial::~Polynomial() {
	delete[] coefs;
}

void Polynomial::swap(Polynomial& p2) {
	std::swap(coefs, p2.coefs);
	std::swap(deg, p2.deg);
}

Polynomial& Polynomial::operator=(const Polynomial& p2) {
	if (this != &p2) {
		Polynomial temp(p2);
		swap(temp);
	}

	return *this;
}

void Polynomial::init(const double* coefs, int deg) {
	this->deg = deg;
	this->coefs = new double[deg + 1];
	for (int i = 0; i <= deg; i++) {
		this->coefs[i] = coefs[i];
	}
}

double Polynomial::value(double x) const {
	double result = 0.0;

	for (int i = deg; i >= 0; i--) {
		result *= x;
		result += coefs[i];
	}

	return result;
}

UnaryFunction* Polynomial::derivative() const {
	if (deg == 0) {
		return new Polynomial();
	}

	double* resultCoefs = new double[deg];

	for (int i = 1; i <= deg; i++) {
		resultCoefs[i-1] = coefs[i] * i;
	}

	UnaryFunction* result = new Polynomial(resultCoefs, deg - 1);
	delete[] resultCoefs;

	return result;
}

Polynomial* Polynomial::clone() const {
	return new Polynomial(*this);
}

string Polynomial::toString(string variable) const {
	ostringstream str;

	for (int i = deg; i > 0; i--) {
		if (coefs[i] != 0) {
			str << coefs[i] << "*" << variable << "^" << i << " + ";
		}
	}

	str << coefs[0];

	return str.str();
}
