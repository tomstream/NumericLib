#include "IterativeMethod.h"


NormalIterativeMethod::NormalIterativeMethod(double sta, double prec, double(*function)(double)) :start(sta), precision(prec), f(function)
{
	calculateTheRoot();
}
void NormalIterativeMethod::calculateTheRoot()
{
	double xCurrent(start), xNext;
	size_t iterT(1);

	while (1)
	{
		xNext = f(xCurrent);
		if (abs(xNext - xCurrent) <= precision)break;
		xCurrent = xNext;
		++iterT;
		if (iterT > 100000)break;
	}
	iterateTime = iterT;
	root = xNext;

}
ostream &operator<< (ostream&os, const NormalIterativeMethod&item)
{
	os << "The root is " << item.root << " , the iteration times are " << item.iterateTime << " ." << endl;
	return os;
}

NewtonIterativeMethod::NewtonIterativeMethod(double sta, double prec, double(*function)(double), double(*functionDerivative)(double))
	:start(sta), precision(prec), f(function), f_d(functionDerivative)
{
	calculateTheRoot();
}

void NewtonIterativeMethod::calculateTheRoot(){
	double xCurrent(start), xNext(start);
	double f_d_value;
	size_t iterT(1);

	while (1){
		f_d_value = f_d(xCurrent);
		if (!f_d_value){ condition = -1; break; }
		xNext = xCurrent - f(xCurrent) / f_d_value;
		if (abs(xNext - xCurrent) <= precision){ condition = 0; break; }
		xCurrent = xNext;
		iterT++;
		if (iterT >= 100000){ condition = 1; break; }
	}
	iteraterTime = iterT;
	root = xNext;
}

ostream &operator<<(ostream&os, const NewtonIterativeMethod&item){
	if (!item.condition)os << "The root is " << item.root << " , the iteration times are " << item.iteraterTime << " ." << endl;
	else if (item.condition == -1)	os << "break in the iteration because of zero-value of f_d." << endl;
	else if (item.condition == 1) os << "break in the iteration because the iterative times are out of range" << "The root is " 
		<< item.root << " , the iteration times are " << item.iteraterTime << " ." << endl;
	return os;
}


AitkenSpeedUpIterativeMethod::AitkenSpeedUpIterativeMethod(double sta, double prec, double(*function)(double))
	:NormalIterativeMethod(sta, prec, function)
{
	calculateTheRoot();
}

void AitkenSpeedUpIterativeMethod::calculateTheRoot()
{
	double xCurrent(start), xNext;
	double yk, zk;
	size_t iterT(0);

	while (1)
	{
		yk = f(xCurrent);
		zk = f(yk);
		xNext = xCurrent - pow(yk - xCurrent, 2) / (zk - 2 * yk + xCurrent);
		if (abs(xNext - xCurrent) <= precision)break;
		xCurrent = xNext;
		++iterT;
		if (iterT > 100000)break;
	}
	iterateTime = iterT;
	root = xNext;

}