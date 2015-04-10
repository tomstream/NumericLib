#pragma once
#include <cmath>
#include <iostream>
using namespace std;

template<size_t n>
class Decimal;

template <size_t n>
ostream &operator<<(ostream &os, Decimal<n> &item)
{
	os << double(item.number) / pow(10, item.afterDot);
	return os;
}


template <size_t n>
istream &operator>>(istream &is, Decimal<n> &item)
{
	double value;
	is >> value;
	item.number = (long long int)(value*pow(10, item.afterDot));
	return is;
}

template <size_t n>
Decimal<n> operator +(Decimal<n> &lhs, Decimal<n> &rhs)
{
	Decimal<n> ret;
	ret.number = lhs.number + rhs.number;
	return ret;
}

template <size_t n>
Decimal<n> operator -(Decimal<n> &lhs, Decimal<n> &rhs)
{
	Decimal<n> ret;
	ret.number =lhs.number - rhs.number;
	return ret;
}

template <size_t n>
Decimal<n> operator *(Decimal<n> &lhs, Decimal<n> &rhs)
{
	Decimal<n> ret;
	ret.number = (long long int)(double(lhs.number) * double(rhs.number)/ pow(10, lhs.decimal())+0.5);
	return ret;
}


template <size_t n>
Decimal<n> operator /(Decimal<n> &lhs, Decimal<n> &rhs)
{
	Decimal<n> ret;
	ret.number = (long long int)((double(lhs.number) / double(rhs.number))*pow(10, lhs.decimal())+0.5);
	return ret;
}

template<size_t n>
bool operator==(const Decimal<n> &lhs, const Decimal<n> &rhs)
{
	return lhs.number == rhs.number;
}

template<size_t n>
bool operator!=(const Decimal<n> &lhs, const Decimal<n> &rhs)
{
	return lhs.number != rhs.number;
}

template<size_t n>
bool operator>(const Decimal<n> &lhs, const Decimal<n> &rhs)
{
	return lhs.number > rhs.number;
}

template<size_t n>
bool operator<(const Decimal<n> &lhs, const Decimal<n> &rhs)
{
	return lhs.number < rhs.number;
}

template<size_t n>
class Decimal
{
public:
	Decimal(double value);
	Decimal() :number(0), afterDot(n){};
	~Decimal();
	size_t decimal(){ return afterDot; }
	long long int& num(){ return number; }
	double val(){ return double(number) / pow(10, number); }

	friend ostream &operator<< <n>(ostream &os, Decimal<n> &item);
	friend istream &operator>> <n>(istream &is,Decimal<n> &item);
	friend Decimal<n> operator + <n>(Decimal<n> &lhs, Decimal<n> &rhs);
	friend Decimal<n> operator - <n>(Decimal<n> &lhs, Decimal<n> &rhs);
	friend Decimal<n> operator * <n>(Decimal<n> &lhs, Decimal<n> &rhs);
	friend Decimal<n> operator / <n>(Decimal<n> &lhs, Decimal<n> &rhs);
	friend bool operator== <n>(const Decimal<n> &lhs, const Decimal<n> &rhs);
	friend bool operator!= <n>(const Decimal<n> &lhs, const Decimal<n> &rhs);
	friend bool operator> <n>(const Decimal<n> &lhs, const Decimal<n> &rhs);
	friend bool operator< <n>(const Decimal<n> &lhs, const Decimal<n> &rhs);

	Decimal<n> &operator=(Decimal<n> &a){this->number = a.number;return *this;}
	Decimal<n> &operator=(const Decimal<n> &a){ this->number = a.number; return *this; }
	Decimal<n> &operator=(double d)
	{this->number = (long long int)(d*pow(10,n));return *this;}
private:
	size_t afterDot;
	long long int number;
};

template <size_t n>
Decimal<n>::Decimal(double value)
	:afterDot(n), number((long long int)((double)(value)*pow(10, n)))
{
}

template <size_t n>
Decimal<n>::~Decimal()
{
}



