#include"Dichotomy.h"
#include"IterativeMethod.h"

int main(void)
{

	Dichotomy test1(0, 1, 5E-4, [](double x){return exp(x) + 10 * x - 2; });
	cout << test1;

	NormalIterativeMethod test2(0, 5E-4, [](double x){return (2 - exp(x)) / 10; });
	cout << test2;

	NewtonIterativeMethod test3(0, 5E-4, [](double x){return exp(x) + 10 * x - 2; }, [](double x){return exp(x) + 10; });
	cout << test3;

	getchar();
	return 0;
}