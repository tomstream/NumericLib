#pragma once

#include<iostream>
#include<utility>
using namespace std;
class Dichotomy{
public:
	Dichotomy() = default;
	Dichotomy(double mininum, double maxinum, double prec, double(*function)(double));
	Dichotomy(Dichotomy& item) :min(item.min), max(item.max), precision(item.precision), f(item.f), iterateTime(item.iterateTime), rootRange(item.rootRange)
	{}
	~Dichotomy() = default;
	friend ostream &operator<<(ostream &os, const Dichotomy&item);

private:
	void calculateTheRoot();

	double min;
	double max;
	double precision;
	double(*f)(double);
	size_t iterateTime;
	pair<double, double> rootRange;
};
ostream &operator<<(ostream &os, const Dichotomy&item);

