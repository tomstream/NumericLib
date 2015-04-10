#pragma once
#include<initializer_list>
#include<iostream>

template<typename T>
class TwoDimensionMatrix
{
public:
	(T*)& operator[](size_t n){ return p[n]; }
	TwoDimensionMatrix(size_t r, size_t c);
	~TwoDimensionMatrix();
	void initialize(initializer_list<T> l);
	size_t c(){ return this->column; }
	size_t r(){ return this->row; }
private:
	T **p;
	size_t column;
	size_t row;
};


template<typename T>
class MatrixEquation
{
public:
	(T*)& operator[](size_t n){ return M[n]; }
	MatrixEquation(size_t numberOfVariable);
	void initialize_M(initializer_list<T> l);
	void initialize_V(initializer_list<T> l);
	void getSolution_Guass();
	void getSolution_Guass_CPC();
private:
	TwoDimensionMatrix<T> M;
public:
	T *v;
	size_t numVariable;
};

template<typename T>
TwoDimensionMatrix<T>::TwoDimensionMatrix(size_t r, size_t c) :p(new T*[r]), column(c), row(r)
{
	for (size_t i = 0; i < row; i++)
	{
		p[i] = new T[column];
		for (size_t j = 0; j < column; j++)
		{
			p[i][j] = 0;
		}
	}
}

template<typename T>
TwoDimensionMatrix<T>::~TwoDimensionMatrix()
{
	for (size_t i = 0; i < row; i++)
	{
		delete[] p[i];
	}
	delete[] p;
}

template<typename T>
void TwoDimensionMatrix<T>::initialize(initializer_list<T> l)
{
	auto iter = l.begin();
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < column; j++)
		{
			if (iter == l.end())return;
			p[i][j] = *iter;
			iter++;
		}
	}
}

template<typename T>
MatrixEquation<T>::MatrixEquation(size_t numberOfVariable) :
M(numberOfVariable, numberOfVariable), v(new T[numberOfVariable]), numVariable(numberOfVariable)
{
	for (size_t i = 0; i < numberOfVariable; i++)
	{
		v[i] = 0;
	}

}

template<typename T>
void MatrixEquation<T>::initialize_M(initializer_list<T> l)
{
	M.initialize(l);
}

template<typename T>
void MatrixEquation<T>::initialize_V(initializer_list<T> l)
{
	auto iter = l.begin();
	for (size_t i = 0; i < numVariable; i++)
	{
		if (iter == l.end())return;
		*(v+i) = (*iter);
		iter++;
	}
}

template<typename T>
void MatrixEquation<T>::getSolution_Guass()
{
	T **q = new T*[numVariable];
	T *w = new T[numVariable];
	T *x = new T[numVariable];

	for (size_t i = 0; i < numVariable; i++)
	{
		q[i] = new T[numVariable];
		for (size_t j = 0; j < numVariable; j++)
		{
			q[i][j] = M[i][j];
		}
		w[i] = v[i];
		x[i] = 0;
	}

	T m;

	for (size_t k = 0; k < numVariable - 1; k++)
	{
		for (size_t i = k + 1; i < numVariable; i++)
		{
			m = q[i][k] / q[k][k];
			for (size_t j = k + 1; j < numVariable; j++)
			{
				q[i][j] = q[i][j] - m*q[k][j];
			}
			w[i] = w[i] - m*w[k];
		}
	}

	x[numVariable - 1] = w[numVariable - 1] / q[numVariable - 1][numVariable - 1];

	for (size_t i = numVariable - 1; i > 0;)
	{
		--i;
		T sum(0);
		for (size_t j = i + 1; j < numVariable; j++)
		{
			sum =sum+ q[i][j] * x[j];
		}
		x[i] = (w[i] - sum) / q[i][i];
	}

	for (size_t i = 0; i < numVariable; i++)
	{
		cout << 'x' << i + 1 << '=' << x[i] << endl;
	}


	delete[] w; delete[] x;
	for (size_t i = 0; i < numVariable; i++)
	{
		delete[] q[i];
	}
	delete[] q;

}

template<typename T>
void MatrixEquation<T>::getSolution_Guass_CPC()
{
	T **q = new T*[numVariable];
	T *w = new T[numVariable];
	T *x = new T[numVariable];

	for (size_t i = 0; i < numVariable; i++)
	{
		q[i] = new T[numVariable];
		for (size_t j = 0; j < numVariable; j++)
		{
			q[i][j] = M[i][j];
		}
		w[i] = v[i];
		x[i] = 0;
	}

	T m;

	for (size_t k = 0; k < numVariable - 1; k++)
	{
		size_t maxRow = k;
		for (size_t i = k + 1; i < numVariable; i++)
		{
			if (q[maxRow][k] < q[i][k])
			{
				maxRow = i;
			}
		}

		swap(q[maxRow], q[k]);
		swap(w[maxRow], w[k]);

		for (size_t i = k + 1; i < numVariable; i++)
		{
			m = q[i][k] / q[k][k];
			for (size_t j = k + 1; j < numVariable; j++)
			{
				q[i][j] = q[i][j] - m*q[k][j];
			}
			w[i] = w[i] - m*w[k];
		}
	}

	x[numVariable - 1] = w[numVariable - 1] / q[numVariable - 1][numVariable - 1];

	for (size_t i = numVariable - 1; i > 0;)
	{
		--i;
		T sum(0);
		for (size_t j = i + 1; j < numVariable; j++)
		{
			sum =sum+ q[i][j] * x[j];
		}
		x[i] = (w[i] - sum) / q[i][i];
	}

	for (size_t i = 0; i < numVariable; i++)
	{
		cout << 'x' << i + 1 << '=' << x[i] << endl;
	}

	delete[] w; delete[] x;
	for (size_t i = 0; i < numVariable; i++)
	{
		delete[] q[i];
	}
	delete[] q;

}
