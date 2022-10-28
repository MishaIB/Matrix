#include "Matrix.h"
#include <iostream>
#include "Exteption.h"
/* ¬ариант 2. ћатрицы
 ласс матриц вещественных чисел произвольного размера.
 ак минимум, предоставить:
Х конструктор с параметрами : размеры матрицы и значение дл€ заполнени€;**
Х оператор() дл€ чтени€ / записи элемента матрицы по указанным индексам;*
Х операторы сложени€ и вычитани€ матриц;**
Х оператор умножени€ матриц;**
Х оператор умножени€ матрицы на скал€р(обеспечить коммутативность);**
Х оператор делени€ матрицы на скал€р;**
Х вычисление следа матрицы.**
«јƒј„ј : ѕривести заданную квадратную матрицу ј к нижнетреугольному виду. */
using namespace std;
Matrix::Matrix() {
	int m = 0;
	int n = 0;
	double** M = NULL;
}


Matrix::Matrix(int m_, int n_) {
	this->n = n_;
	this->m = m_;
	M = new double* [m];
	for (int i = 0; i < m; i++) {
		M[i] = new double[n];
	}
}

Matrix::Matrix(int m_, int n_, double value) {
	this->n = n_;
	this->m = m_;
	M = new double* [m];
	for (int i = 0; i < m; i++) {
		M[i] = new double[n];
	}
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			this->M[i][j] = value;
		}
}


Matrix::Matrix(const Matrix& M_) {
	m = M_.m;
	n = M_.n;
	M = new double* [m];
	for (int i = 0; i < m; i++) {
		M[i] = new double[n];
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			M[i][j] = M_.M[i][j];
		}
	}
}


int Matrix::GetM()  {
	return m;
}


int Matrix::GetN()  {
	return n;
}


void Matrix::Print() {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << M[i][j] << '\t';
		}
	}

}


double& Matrix::operator ()(int i, int j)
{
	if ((i >= 0) || (i < m) || (j >= 0) || (j < n))
		return M[i][j];
	else throw EInvalidIndex();
}
Matrix& Matrix::operator ()(int i, int j, double value)
{
	if ((i >= 0) && (i <= m) && (j >= 0) && (j <= n))
		this->M[i][j] = value;
	else throw EInvalidIndex();
}

Matrix Matrix::operator + (const Matrix& B) {

	if (n != B.n || m != B.m) throw EInvalidSize();
	Matrix tmp(m, n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			tmp.M[i][j] = M[i][j] + B.M[i][j];
		}
	}
	return tmp;
}


Matrix Matrix::operator - (const Matrix& B) {
	if (n != B.n || m != B.m) throw EInvalidSize();
	int m_ = GetM();
	int n_ = GetN();
	Matrix tmp(m_, n_);
	for (int i = 0; i < m_; i++) {
		for (int j = 0; j < n_; j++) {
			tmp.M[i][j] = M[i][j] - B.M[i][j];
		}
	}
	return tmp;
}


Matrix Matrix::operator * (const Matrix& B) {
	if (m != B.n) throw EInvalidMull();
	int m_ = GetM();
	int n_ = B.n;
	Matrix tmp(m, n);
	for (int i = 0; i < m_; i++)
	{
		for (int j = 0; j < m_; j++)
		{
			tmp.M[i][j] = 0;
			for (int k = 0; k < n_; k++)
			{
				tmp.M[i][j] += M[i][k] * B.M[k][j];
			}
		}
	}
	return tmp;
}


Matrix Matrix::operator * (const double a) {
	Matrix tmp(m, n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			tmp.M[i][j] = M[i][j] * a;
		}
	}
	return tmp;
}


Matrix Matrix::operator / (double a) {
	if (a == 0) throw EdivisionZero();
	Matrix tmp(m, n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			tmp.M[i][j] = M[i][j] / a;
		}
	}
	return tmp;
}


double Matrix::Trace() {
	if (n != m)  throw EInvalidQuadrate();
	double sum = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				sum += M[i][j];
			}
		}
	}
	return sum;
}


Matrix Matrix::Triangular() {
	if (n != m)  throw EInvalidQuadrate();
	double r;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			r = M[j][i] / M[i][i];
			for (int k = 0; k < n + 1; k++) {
				M[j][k] = M[j][k] - r * M[i][k];
			}
		}
	}
	return *this;
}
void Matrix::Transpose() {
	if (n != m) throw EInvalidQuadrate();
	double s;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++) {
			s = M[i][j];
			M[i][j] = M[j][i];
			M[j][i] = s;
		}
}
ostream& operator<< (ostream& s, const Matrix& matrix) {

	for (int i = 0; i < matrix.m; i++) {
		for (int j = 0; j < matrix.n; j++)
			s << matrix.M[i][j] << " ";
		s << "\n";
	}
	return s;
}


