#include "Dichotomy.h"

void Dichotomy::calculateTheRoot()
{
	double yMin, yMiddle, yMax;
	double middle;
	size_t iteratorTimes(0);

	yMin = f(min); yMax = f(max);
	if (yMin*yMax > 0 && precision != 0){
		iterateTime = 0;
		return;
	}
	while (max - min > precision&&iteratorTimes<1000000)
	{
		middle = (min + max) / 2;
		yMiddle = f(middle);
		if (yMiddle*yMax < 0){
			min = middle;
			yMin = yMiddle;
		}
		else if (yMiddle*yMin<0)
		{
			max = middle;
			yMax = yMiddle;
		}
		else  min = max = middle;
		++iteratorTimes;
	}
	iterateTime = iteratorTimes;
	rootRange.first = min;
	rootRange.second = max;

}

Dichotomy::Dichotomy(double mininum, double maxinum, double prec, double(*function)(double)) :min(mininum), max(maxinum), precision(prec), f(function)
{
	calculateTheRoot();
}

ostream &operator<< (ostream&os, const Dichotomy&item)
{
	if (item.iterateTime == 0)os << "cannot calcucate the root through dichotomy" << endl;
	else os << "the range of the root is in " << item.rootRange.first << " , the iteration times are " << item.iterateTime << " ." << endl;
	return os;
}
