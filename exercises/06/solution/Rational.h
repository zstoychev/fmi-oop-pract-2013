#ifndef RATIONAL_H
#define RATIONAL_H

#include <ostream>

class Rational {
	int num;
	int denom;

public:
	Rational(int num = 0, int denom = 1);

	Rational add(const Rational& rat) const;
	Rational subtract(const Rational& rat) const;
	Rational multiply(const Rational& rat) const;
	Rational divide(const Rational& rat) const;
	Rational opposite() const;
	Rational inverse() const;

	int getNum() const;
	int getDenom() const;
	bool isPos() const;
	double toDouble() const;

	void print() const;

	Rational operator+(const Rational& rat) const;
	Rational operator-(const Rational& rat) const;
	Rational operator*(const Rational& rat) const;
	Rational operator/(const Rational& rat) const;
	Rational& operator+=(const Rational& rat);
	Rational& operator-=(const Rational& rat);
	Rational& operator*=(const Rational& rat);
	Rational& operator/=(const Rational& rat);

	// These would have been unnecessary if we didn't have conversion operators
	Rational operator +(int i) const;
	Rational operator -(int i) const;
	Rational operator *(int i) const;
	Rational operator /(int i) const;

	bool operator <(const Rational& rat) const;
	bool operator <=(const Rational& rat) const;
	bool operator >(const Rational& rat) const;
	bool operator >=(const Rational& rat) const;
	bool operator ==(const Rational& rat) const;
	bool operator !=(const Rational& rat) const;

	operator bool() const;
	operator int() const;
	operator float() const;
	operator double() const;

	Rational operator -() const;
	Rational operator ~() const;
	Rational operator ^(int power) const;
};

Rational operator +(int i, const Rational& rat);
Rational operator -(int i, const Rational& rat);
Rational operator *(int i, const Rational& rat);
Rational operator /(int i, const Rational& rat);

std::ostream& operator <<(std::ostream& output, const Rational& rat);

#endif
