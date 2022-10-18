/* ������� 2. �������
����� ������ ������������ ����� ������������� �������.
��� �������, ������������:
� ����������� � ����������� : ������� ������� � �������� ��� ����������;**
� ��������() ��� ������ / ������ �������� ������� �� ��������� ��������;
� ��������� �������� � ��������� ������;
� �������� ��������� ������;
� �������� ��������� ������� �� ������(���������� ���������������);
� �������� ������� ������� �� ������;
� ���������� ����� �������.
������ : �������� �������� ���������� ������� � � ����������������� ����. */
#include <iostream>
class Matrix {
private:
	int n;
	int m;
	double** M;
public:
	Matrix();
	Matrix(int m_, int n_);
	Matrix(const Matrix* M_);
	void Print();
	int GetM();
	int GetN();
	double& operator ()(int i, int j);
	Matrix& operator ()(int i, int j, double value);
	Matrix operator + (Matrix& B);
	Matrix operator - (Matrix& B);
	Matrix operator * (Matrix& B);
	Matrix operator * (const double a);
	Matrix operator / (const double a);
	double Trace();
	Matrix Triangular();
	void Transpose();
	friend std::ostream& operator << (std::ostream& s, const Matrix& matrix);
};
