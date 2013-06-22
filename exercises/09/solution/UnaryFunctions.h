#ifndef UNARYFUNCTIONS_H
#define UNARYFUNCTIONS_H

#include <string>
#include <iostream>
using namespace std;

class UnaryFunction {
public:
	virtual ~UnaryFunction() {}
	virtual double value(double x) const = 0;
	virtual UnaryFunction* derivative() const = 0;
	virtual UnaryFunction* clone() const = 0;
	virtual string toString(string variable = "x") const = 0;
};

class Polynomial : public UnaryFunction {
	double* coefs;
	int deg;

	void init(const double* coefs, int deg);
public:
	Polynomial();
	Polynomial(const double* coefs, int deg);
	Polynomial(const Polynomial& p2);
	virtual ~Polynomial();
	void swap(Polynomial& p2);
	Polynomial& operator=(const Polynomial& p2);
	virtual double value(double x) const;
	virtual UnaryFunction* derivative() const;
	virtual Polynomial* clone() const;
	virtual string toString(string variable = "x") const;
};

enum TrigonometricFunctionType{
	SIN,
	COS
};

class TrigonometricFunction : public UnaryFunction {
	TrigonometricFunctionType type;
	bool isSignNonNegative;
public:
	TrigonometricFunction(TrigonometricFunctionType type, bool isSignNonNegative = true);
	virtual double value(double x) const;
	virtual UnaryFunction* derivative() const;
	virtual TrigonometricFunction* clone() const;
	virtual string toString(string variable = "x") const;
};

class LinearCombination : public UnaryFunction {
	double coef1;
	UnaryFunction* func1;
	double coef2;
	UnaryFunction* func2;
public:
	LinearCombination(double coef1, const UnaryFunction& func1, double coef2, const UnaryFunction& func2);
	LinearCombination(const LinearCombination& lc2);
	virtual ~LinearCombination();
	void swap(LinearCombination& lc2);
	LinearCombination& operator=(const LinearCombination& lc2);
	virtual double value(double x) const;
	virtual UnaryFunction* derivative() const;
	virtual LinearCombination* clone() const;
	virtual string toString(string variable = "x") const;
};

class Product : public UnaryFunction {
	UnaryFunction* func1;
	UnaryFunction* func2;
public:
	Product(const UnaryFunction& func1, const UnaryFunction& func2);
	Product(const Product& p2);
	virtual ~Product();
	void swap(Product& p2);
	Product& operator=(const Product& p2);
	virtual double value(double x) const;
	virtual UnaryFunction* derivative() const;
	virtual Product* clone() const;
	virtual string toString(string variable = "x") const;
};

class Superposition : public UnaryFunction {
	UnaryFunction* outerFunc;
	UnaryFunction* innerFunc;
public:
	Superposition(const UnaryFunction& outerFunc, const UnaryFunction& innerFunc);
	Superposition(const Superposition& s2);
	virtual ~Superposition();
	void swap(Superposition& s2);
	Superposition& operator=(const Superposition& s2);
	virtual double value(double x) const;
	virtual UnaryFunction* derivative() const;
	virtual Superposition* clone() const;
	virtual string toString(string variable = "x") const;
};

ostream& operator<<(ostream& output, const UnaryFunction& uf);

#endif
