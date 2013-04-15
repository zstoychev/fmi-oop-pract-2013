#include <cmath>
#include <cassert>
#include <iostream>
#include "Rational.h"
#include "util.h"
using std::abs;
using std::pow;

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
	std::cout << *this;
}

Rational Rational::operator +(const Rational& rat) const {
	return add(rat);
}

Rational Rational::operator -(const Rational& rat) const {
	return subtract(rat);
}

Rational Rational::operator *(const Rational& rat) const {
	return multiply(rat);
}

Rational Rational::operator /(const Rational& rat) const {
	return divide(rat);
}

Rational& Rational::operator +=(const Rational& rat) {
	*this = *this + rat;
	return *this;
}

Rational& Rational::operator -=(const Rational& rat) {
	*this = *this - rat;
	return *this;
}

Rational& Rational::operator *=(const Rational& rat) {
	*this = *this * rat;
	return *this;
}

Rational& Rational::operator /=(const Rational& rat) {
	*this = *this / rat;
	return *this;
}

Rational Rational::operator +(int i) const {
	return *this + Rational(i);
}

Rational Rational::operator -(int i) const {
	return *this - Rational(i);
}

Rational Rational::operator *(int i) const {
	return *this * Rational(i);
}

Rational Rational::operator /(int i) const {
	return *this / Rational(i);
}

bool Rational::operator <(const Rational& rat) const {
	return num * rat.denom < rat.num * denom;
}

bool Rational::operator <=(const Rational& rat) const {
	return *this < rat || *this == rat;
}

bool Rational::operator >(const Rational& rat) const {
	return !(*this <= rat);
}

bool Rational::operator >=(const Rational& rat) const {
	return !(*this < rat);
}

bool Rational::operator ==(const Rational& rat) const {
	return num == rat.num && denom == rat.denom;
}

bool Rational::operator !=(const Rational& rat) const {
	return !(*this == rat);
}

Rational::operator bool() const {
	return num == 0;
}

Rational::operator int() const {
	return num / denom;
}

Rational::operator float() const {
	return float(num) / denom;
}

Rational::operator double() const {
	return double(num) / denom;
}

Rational Rational::operator -() const {
	return opposite();
}

Rational Rational::operator ~() const {
	return inverse();
}

Rational Rational::operator ^(int power) const {
	return Rational((int) pow(double(num), power), (int) pow(double(denom), power));
}

Rational operator +(int i, const Rational& rat) {
	return rat + i;
}

Rational operator -(int i, const Rational& rat) {
	return rat - i;
}

Rational operator *(int i, const Rational& rat) {
	return rat * i;
}

Rational operator /(int i, const Rational& rat) {
	return rat / i;
}

std::ostream& operator <<(std::ostream& output, const Rational& rat) {
	output << rat.getNum() << "/" << rat.getDenom();
	
	return output;
}
