#include <conio.h>
#include <iostream>
using namespace std;

int get_key()
{
    int key = _getch();
    if ((key == 0) || (key == 224))
        key = _getch();
    return key;
}

int menu1()
{
    cout << "\nЧто вы хотите сделать?.\n\n"
        "1 - выполнить сложение матриц\n"
        "2 - выполнить вычитание матриц\n"
        "3 - выполнить умножение матрицы на матрицу\n"
        "4 - выполнить умножение матрицы на скаляр\n"
        "5 - выполнить деление матрицы на скаляр\n"
        "6 - вычислить след квадратной матрицы\n"
        "7 - преобразовать квадратную матрицу к нижнетреугольному виду\n\n"
        "Выход: Esc";


    while (true)
    {
        int key = get_key();
        if ((key == 27) || (key > '0' && key <= '7'))
            return key;
    }
}

int menu2()
{
    cout << "\n\n";
    cout << "����������: Enter";
    while (true)
    {
        int key = get_key();
        if (key == 13) return key;
    }
}