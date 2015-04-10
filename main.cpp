
#include "Decimal.h"
#include "MatrixCalculate.h"

int main(void)
{
	MatrixEquation<double> M0(4);
	M0.initialize_M({ 1.1348, 3.8326, 1.1651, 3.4017,
		0.5301, 1.7875, 2.5330, 1.5435,
		3.4129, 4.9317, 8.7643, 1.3142,
		1.2371, 4.9998, 10.6721, 0.0147 });
	M0.initialize_V({ 9.5342, 6.3941, 18.4231, 16.9237 });

	M0.getSolution_Guass();
	cout << endl;
	M0.getSolution_Guass_CPC();
	cout << endl;

	MatrixEquation<float> M1(4);
	M1.initialize_M({ float(1.1348), float(3.8326), float(1.1651), float(3.4017),
					float(0.5301), float(1.7875), float(2.5330), float(1.5435),
					float(3.4129),float(4.9317),float(8.7643),float(1.3142),
					float(1.2371),float(4.9998),float(10.6721),float(0.0147)});
	M1.initialize_V({float(9.5342),float(6.3941),float(18.4231),float(16.9237)});

	M1.getSolution_Guass();
	cout<<endl;
	M1.getSolution_Guass_CPC();
	cout << endl;

	MatrixEquation<Decimal<4>> M2(4);
	M2.initialize_M({ 1.1348, 3.8326, 1.1651, 3.4017,
		0.5301, 1.7875, 2.5330, 1.5435,
		3.4129, 4.9317, 8.7643, 1.3142,
		1.2371, 4.9998, 10.6721, 0.0147 });
	M2.initialize_V({ 9.5342, 6.3941, 18.4231, 16.9237 });

	M2.getSolution_Guass();
	cout << endl;
	M2.getSolution_Guass_CPC();
	cout << endl;

	getchar();
	return 0;
}