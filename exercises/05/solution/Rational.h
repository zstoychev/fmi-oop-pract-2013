#ifndef RATIONAL_H
#define RATIONAL_H

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
};

#endif
