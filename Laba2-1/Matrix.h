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
	Matrix(int n_, int m_);
	Matrix(const Matrix* a);
	void Print();
	int Getm();
	int Getn();
	double& operator ()(int i, int j, double data);
	Matrix operator + (Matrix& B);
	Matrix operator - (Matrix& B);
	Matrix operator * (Matrix& B);
	Matrix operator * (double a);
	Matrix operator / (double a);
	double trace();
	Matrix triangular();
	~Matrix();
};
