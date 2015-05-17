

#include "MatrixCalculate.h"
using namespace std;

int main(void)
{
	MatrixEquation<double> M0(6);
	M0.initialize_M({ 4,-1,0,-1,0,0
					,-1,4,-1,0,-1,0
					,0,-1,4,-1,0,-1
					,-1,0,-1,4,-1,0
					,0,-1,0,-1,4,-1
					,0,0,-1,0,-1,4});
	M0.initialize_V({ 0,5,-2,5,-2,6 });

	cout << "雅可比迭代法" << endl;
	M0.getSolution_Jacobi_I({0,0,0,0,0,0}, 1e-4);

	cout << endl;

	cout << "高斯—塞德尔迭代法" << endl;
	M0.getSolution_GS_I({ 0, 0, 0, 0, 0, 0 }, 1e-4);
	cout << endl;

	cout << "SOR迭代法" << endl;
	cout << "omega=1.334" << endl;
	M0.getSolution_SOR_I({0,0,0,0,0,0}, 1.334,1e-4);
	cout << endl;
	cout << "omega=1.95" << endl;
	M0.getSolution_SOR_I({ 0, 0, 0, 0, 0, 0 }, 1.99, 1e-4);
	cout << endl;
	cout << "omega=0.95" << endl;
	M0.getSolution_SOR_I({ 0, 0, 0, 0, 0, 0 }, 0.95, 1e-4);

	getchar();
	return 0;
}