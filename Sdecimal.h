#pragma once
#include <cmath>
#include <iostream>
#include <cfloat>
using namespace std;

template<size_t n>
class Sdecimal;

template <size_t n>
ostream &operator<<(ostream &os, Sdecimal<n> &item)
{
	os << item.val();
	return os;
}


template <size_t n>
istream &operator>>(istream &is, Sdecimal<n> &item)
{
	double value;
	is >> value;
	item.doubleToSDecimal(value);
	return is;
}

template <size_t n>
Sdecimal<n> operator +(Sdecimal<n> &lhs, Sdecimal<n> &rhs)
{
	Sdecimal<n> ret;
	ret.doubleToSDecimal(lhs.val() + rhs.val());
	return ret;
}

template <size_t n>
Sdecimal<n> operator -(Sdecimal<n> &lhs, Sdecimal<n> &rhs)
{
	Sdecimal<n> ret;
	ret.doubleToSDecimal(lhs.val() - rhs.val());
	return ret;
}

template <size_t n>
Sdecimal<n> operator *(Sdecimal<n> &lhs, Sdecimal<n> &rhs)
{
	Sdecimal<n> ret;
	ret.doubleToSDecimal((lhs.number*rhs.number)*pow(10,lhs.exponent+rhs.exponent));
	return ret;
}


template <size_t n>
Sdecimal<n> operator/(Sdecimal<n> &lhs, Sdecimal<n> &rhs)
{
	Sdecimal<n> ret;
	ret.doubleToSDecimal((lhs.number*100000/rhs.number)*pow(10, lhs.exponent - rhs.exponent-5));
	return ret;
}

template<size_t n>
bool operator==(const Sdecimal<n> &lhs, const Sdecimal<n> &rhs)
{
	return abs(lhs.val() - rhs.val())<DBL_EPSILON;
}

template<size_t n>
bool operator!=(const Sdecimal<n> &lhs, const Sdecimal<n> &rhs)
{
	return !(lhs==rhs);
}

template<size_t n>
bool operator>(const Sdecimal<n> &lhs, const Sdecimal<n> &rhs)
{
	return lhs.val() > rhs.val();
}

template<size_t n>
bool operator<( Sdecimal<n> &lhs,  Sdecimal<n> &rhs)
{
	return lhs.val() < rhs.val();
}

template<size_t n>
class Sdecimal
{
public:
	Sdecimal(double value);
	Sdecimal() :number(0), effectBit(n){};
	~Sdecimal();

	double val(){ return double(number * pow(10, exponent)); }

	friend ostream &operator<< <n>(ostream &os, Sdecimal<n> &item);
	friend istream &operator>> <n>(istream &is, Sdecimal<n> &item);
	friend Sdecimal<n> operator + <n>(Sdecimal<n> &lhs, Sdecimal<n> &rhs);
	friend Sdecimal<n> operator - <n>(Sdecimal<n> &lhs, Sdecimal<n> &rhs);
	friend Sdecimal<n> operator * <n>(Sdecimal<n> &lhs, Sdecimal<n> &rhs);
	friend Sdecimal<n> operator / <n>(Sdecimal<n> &lhs, Sdecimal<n> &rhs);
	friend bool operator== <n>(const Sdecimal<n> &lhs, const Sdecimal<n> &rhs);
	friend bool operator!= <n>(const Sdecimal<n> &lhs, const Sdecimal<n> &rhs);
	friend bool operator> <n>( Sdecimal<n> &lhs, Sdecimal<n> &rhs);
	friend bool operator< <n>(const Sdecimal<n> &lhs, const Sdecimal<n> &rhs);

	Sdecimal<n> &operator=(Sdecimal<n> &a){ this->number = a.number; this->exponent = a.exponent; return *this; }//
	Sdecimal<n> &operator=(const Sdecimal<n> &a){ this->number = a.number; this->exponent = a.exponent; return *this; }//
	Sdecimal<n> &operator=(double d)
	{
		doubleToSDecimal(d); return *this;
	}
private:
	void doubleToSDecimal(double d);
	size_t effectBit;
	int number;
	int exponent;
};

template <size_t n>
Sdecimal<n>::Sdecimal(double value)
	:effectBit(n)
{
	doubleToSDecimal(value);
}

template <size_t n>
Sdecimal<n>::~Sdecimal()
{
}


template <size_t n>
void Sdecimal<n>::doubleToSDecimal(double d)
{
	if (abs(d) <DBL_EPSILON)
	{
		number = 0; exponent = 0;
		return;
	}
	int tmpExponent(0);
	double tmpNumber(d);
	
	if (abs(d) < pow(10,effectBit-1))
	{
		
		while (abs(tmpNumber) < pow(10,effectBit-1))
		{
			tmpNumber *= 10;
			tmpExponent--;
		}

	}
	else if (abs(d) >= pow(10, effectBit))
	{
		while (abs(tmpNumber) >= pow(10, effectBit))
		{
			tmpNumber /= 10;
			tmpExponent++;
		}
	}
	number = int(tmpNumber+0.5);
	exponent = tmpExponent;
}
