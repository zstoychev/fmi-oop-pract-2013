#include <cmath>
#include <cassert>
#include <iostream>
#include "Rational.h"
#include "util.h"
using std::abs;

Rational::Rational(int num, int denom) {
	assert(denom != 0);

	int g = gcd(abs(num), abs(denom));

	this->num = sign(denom) * num / g;
	this->denom = abs(denom) / g;
}

Rational Rational::add(const Rational& rat) const {
	return Rational(
		num * rat.denom + rat.num * denom,
		denom * rat.denom
	);
}

Rational Rational::subtract(const Rational& rat) const {
	return add(rat.opposite());
}

Rational Rational::multiply(const Rational& rat) const {
	return Rational(num * rat.num, denom * rat.denom);
}

Rational Rational::divide(const Rational& rat) const {
	assert(rat.num != 0);

	return multiply(rat.inverse());
}

Rational Rational::opposite() const {
	return Rational(-num, denom);
}

Rational Rational::inverse() const {
	return Rational(sign(num) * denom, abs(num));
}

int Rational::getNum() const {
	return num;
}

int Rational::getDenom() const {
	return denom;
}

bool Rational::isPos() const {
	return num > 0;
}

double Rational::toDouble() const {
	return double(num) / denom;
}

void Rational::print() const {
	std::cout << num << "/" << denom;
}
