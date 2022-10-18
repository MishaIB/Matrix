
#include "Exteption.h"
#include "Matrix.h"
#include <conio.h>
#include <string>
#include <iostream>
#include <ostream>
using namespace std;
/* ¬ариант 2. ћатрицы
 ласс матриц вещественных чисел произвольного размера.
 ак минимум, предоставить:
Х конструктор с параметрами : размеры матрицы и значение дл€ заполнени€;
Х оператор() дл€ чтени€ / записи элемента матрицы по указанным индексам;
Х операторы сложени€ и вычитани€ матриц;
Х оператор умножени€ матриц;
Х оператор умножени€ матрицы на скал€р(обеспечить коммутативность);
Х оператор делени€ матрицы на скал€р;
Х вычисление следа матрицы.
«јƒј„ј : ѕривести заданную квадратную матрицу ј к нижнетреугольному виду. */
int GetKey()
{
	int key = _getch();
	if ((key == 0) || (key == 224))
		key = _getch();
	return key;
}


int Menu1()
{
	cout << endl << ("\n«апустить программу - Enter\n¬ыход - Esc\n") << endl;
	while (true)
	{
		int key = GetKey();
		if ((key == 27) || (key == 13)) return key;
	}
}


int Menu2()
{
	cout << "\n„то вы хотите сделать?.\n\n"
		"1 - выполнить сложение матриц\n"
		"2 - выполнить вычитание матриц\n"
		"3 - выполнить умножение матрицы на матрицу\n"
		"4 - выполнить умножение матрицы на скал€р\n"
		"5 - выполнить деление матрицы на скал€р\n"
		"6 - вычислить след квадратной матрицы\n"
		"7 - преобразовать квадратную матрицу к нижнетреугольному виду\n\n"
		"¬ыход: Esc\n";


	while (true)
	{
		int key = GetKey();
		if ((key == 27) || (key > '0' && key <= '7'))
			return key;
	}
}


void SetData(Matrix& Mass,int m, int n) {
	double value;
	cout << "¬ведите значени€\n";
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << "[" << i << "][" << j << "]:";
			cin >> value;
			Mass(i, j, value);
		}
	}
}


void RandValue(Matrix& Mass, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			Mass(i, j,rand()%9);
		}
	}
}


int main() {
	Matrix C,B;
	setlocale(LC_ALL, "");
	int column, row;
	while (true) {
		system("cls");
		cout << "¬ведите размеры матрицы ј (число столбцов и строк):";
		cin >> column >> row;
		Matrix A(column, row);
		SetData(A, column, row);
		cout << "¬ведите размеры матрицы B (число столбцов и строк):";
		cin >> column >> row;
		Matrix B(column, row);
		RandValue(B, column, row);
		cout << "A:\n" << A << endl;
		cout << "B:\n" << B << endl;
		int m1 = Menu1();
		if (m1 == 27) break;
		while (true) {
			int m2 = Menu2();
			if (m2 == 27) break;
			int scal;
			switch (m2)
			{
			case 49:
				system("cls");
				cout << "–езультат сложени€ матриц:\n";
				try {
					C = A + B;
					cout << C;
				}
				catch (Exteption& er) { er.Print(); }
				break;
			case 50:
				system("cls");
				cout << "–езультат вычитани€ матриц:\n";
				try {
					C = A - B;
					cout << C;
				}
				catch (Exteption& er) { er.Print(); }
				break;
			case 51:
				system("cls");
				cout << "–езультат умножени€ матриц:\n";
				try {
					C = A * B;
					cout << C;
				}
				catch (Exteption& er) { er.Print(); }
				break;
			case 52:
				cout << "¬ведите скал€р:";
				cin >> scal;
				system("cls");
				cout << "–езультат умножение матрицы на скал€р:\n";
				try {
					C = A * scal;
					cout << C;
				}
				catch (Exteption& er) { er.Print(); }
				break;
			case 53:
				system("cls");
				cout << "–езультат делени€ матрицы на скал€р:\n";
				cout << "¬ведите скал€р:";
				cin >> scal;
				try {
					C = A / scal;
					cout << C;
				}
				catch (Exteption& er) { er.Print(); }
				break;
			case 54:
				system("cls");
				cout << "–езультат вычислени€ следа матрицы:\n";
				try {
					cout << A.Trace();
				}
				catch (Exteption& er) { er.Print(); }
				break;
			case 55:
				system("cls");
				try {
					cout << "–езультат преобразовани€ матрицы к нижнетреугольному виду:\n";
					C = A.Triangular();
					C.Transpose();
					cout << C;
				}
				catch (Exteption& er) { er.Print(); }
				break;
			}
		}
	}
	return 0;
}