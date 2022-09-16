#include "Matrix.h"
#include <iostream>
/* ¬ариант 2. ћатрицы
 ласс матриц вещественных чисел произвольного размера.
 ак минимум, предоставить:
Х конструктор с параметрами : размеры матрицы и значение дл€ заполнени€;**
Х оператор() дл€ чтени€ / записи элемента матрицы по указанным индексам;*
Х операторы сложени€ и вычитани€ матриц;**
Х оператор умножени€ матриц;**
Х оператор умножени€ матрицы на скал€р(обеспечить коммутативность);
Х оператор делени€ матрицы на скал€р;
Х вычисление следа матрицы.
«јƒј„ј : ѕривести заданную квадратную матрицу ј к нижнетреугольному виду. */
using namespace std;
Matrix::Matrix() {
	int m = 0;
	int n = 0;
	double**M = nullptr;
}
Matrix::Matrix(int n_, int m_) {
	int n = n_;
	int m = m_;
	M = new double* [m];
	for (int i = 0; i < n; i++) {
		M[i] = new double [n];
	}
}

Matrix::Matrix(const Matrix* M_) {
	m = M_->m;
	n = M_->n;
	M = new double* [m];
	for (int i = 0; i < n; i++) {
		M[i] = new double[n];
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; n < j;j++) {
			M[i][j] = M_->M[i][j];
		}
	}
}
int Matrix::Getm() {
	return m;
}
int Matrix::Getn() {
	return n;
}
void Matrix::Print() {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << M[i][j] << '\t';
		}
	}

}
double& Matrix::operator ()(int i, int j, double data)
{
	return M[i][j];
}
 Matrix Matrix::operator + (Matrix& B) {
	int m_ = Getm();
	int n_ = B.Getn();
	Matrix tmp(m_, n_);
	for (int i = 0; i < m_; i++) {
		for (int j = 0; j < n_; j++) {
			tmp.M[i][j] = M[i][j] + B.M[i][j];
		}
	}
	return tmp;
}
 Matrix Matrix::operator - (Matrix& B) {
	 int m_ = Getm();
	 int n_ = Getn();
	 Matrix tmp(m_, n_);
	 for (int i = 0; i < m_; i++) {
		 for (int j = 0; j < n_; j++) {
			 tmp.M[i][j] = M[i][j] - B.M[i][j];
		 }
	 }
	 return tmp;
 }
 Matrix Matrix::operator * (Matrix& B) {
	 int m_ = Getm();
	 int n_ = B.Getn();
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
Matrix::~Matrix() {

	delete[]M;
}