#pragma once
#include<iostream>
using namespace std;

class NormalIterativeMethod{
public:
	NormalIterativeMethod() = default;
	NormalIterativeMethod(double sta, double prec, double(*function)(double));
	virtual ~NormalIterativeMethod() = default;
	friend ostream &operator<<(ostream &os, const NormalIterativeMethod&item);
protected:
	virtual void calculateTheRoot();
	double start;
	double precision;
	double(*f)(double);
	double iterateTime;
	double root;
};
ostream &operator<<(ostream &os, const NormalIterativeMethod&item);

class NewtonIterativeMethod
{
public:
	NewtonIterativeMethod(double sta, double prec, double(*function)(double), double(*functionDerivative)(double));
	friend ostream &operator<<(ostream&os, const NewtonIterativeMethod&item);
private:
	void calculateTheRoot();
	double start;
	double precision;
	double(*f)(double);
	double(*f_d)(double);
	int condition;
	double iteraterTime;
	double root;
};

class AitkenSpeedUpIterativeMethod :public NormalIterativeMethod
{
public:
	AitkenSpeedUpIterativeMethod() = default;
	AitkenSpeedUpIterativeMethod(double sta, double prec, double(*function)(double));
	~AitkenSpeedUpIterativeMethod() = default;
protected:
	virtual void calculateTheRoot() override;
};

