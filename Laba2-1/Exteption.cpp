#include <iostream>
#include "Exteption.h"
using namespace std;


void EInvalidSize::print(){
	cout << endl << "������:\n�������� �� ��������. ������� ������ �� ���������" << endl;
}


void EInvalidIndex::print() {
	cout << endl << "������:\n�������� �� ��������. ��� �������� �������������� �� ���� �������� " << endl;
}

void EInvalidMull::print(){
	cout << endl << "������:\n����� �������� ������� A �� ����� ����� ����� ������� B" << endl;
}


void EInvalidQuadrate::print(){
	cout << endl << "������:\n������� �� ����������" << endl;
}


void EdivisionZero::print(){
	cout << endl << "������:\n������� �� ����" << endl;
}