/* ¬ариант 2. ћатрицы
 ласс матриц вещественных чисел произвольного размера.
 ак минимум, предоставить:
Х конструктор с параметрами : размеры матрицы и значение дл€ заполнени€;**
Х оператор() дл€ чтени€ / записи элемента матрицы по указанным индексам;
Х операторы сложени€ и вычитани€ матриц;
Х оператор умножени€ матриц;
Х оператор умножени€ матрицы на скал€р(обеспечить коммутативность);
Х оператор делени€ матрицы на скал€р;
Х вычисление следа матрицы.
«јƒј„ј : ѕривести заданную квадратную матрицу ј к нижнетреугольному виду. */
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
