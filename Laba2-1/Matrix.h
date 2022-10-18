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
