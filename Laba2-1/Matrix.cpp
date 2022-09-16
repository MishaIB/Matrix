#include "Matrix.h"
#include <iostream>
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
Matrix::~Matrix() {
	delete[]M;
}