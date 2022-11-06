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
	int n=0;
	int m=0;
	double** M=NULL;
public:
	Matrix();
	Matrix(int m_, int n_);
	Matrix(int m_, int n_, double value);
	Matrix(const Matrix& M_);
	void Print ();
	int GetM() const;
	int GetN() const;
	double& operator ()(int i, int j);
	Matrix& operator ()(int i, int j, double value);
	Matrix operator + (const Matrix& B);
	Matrix operator - (const Matrix& B);
	Matrix operator * (const Matrix& B);
	Matrix operator * (const double a);
	Matrix operator / (const double a);
	double Trace();
	Matrix Triangular();
	void Transpose();
	friend std::ostream& operator << (std::ostream& s, const Matrix& matrix);
};
