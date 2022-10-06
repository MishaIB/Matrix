#include <iostream>
#include "Exteption.h"
using namespace std;


void EInvalidSize::print(){
	cout << endl << "Ошибка:\nОперация не вохможна. Размеры матриц не совпадают" << endl;
}


void EInvalidIndex::print() {
	cout << endl << "Ошибка:\nОперация не возможна. Нет элемента расположенного по этим индексам " << endl;
}

void EInvalidMull::print(){
	cout << endl << "Ошибка:\nЧисло столбцов матрицы A не равно числу строк матрицы B" << endl;
}


void EInvalidQuadrate::print(){
	cout << endl << "Ошибка:\nМатрица не квадратная" << endl;
}


void EdivisionZero::print(){
	cout << endl << "Ошибка:\nДеление на ноль" << endl;
}