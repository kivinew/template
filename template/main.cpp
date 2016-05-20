/* ������������ ������ �4. ���������� �������.
��������� �.�. (����� 09.2015).
������� �9: ���� (������ - �������� ������������).*/

#include "Stack.h"
#include <iostream>
#include <clocale>
#include <Windows.h>
#include "Complex.h"

#define ONE         49
#define TWO         50
#define THREE       51
#define FOUR        52
using namespace std;

bool menu();
void gotoxy(int, int);

Stack<Complex> *objPtr=NULL;

int main()
{
    setlocale(LC_ALL, "Russian");
    int max;
    cout<<"������ �����: ";
    cin>>max;
    Stack<Complex> obj(max);
    objPtr = &obj;
    while(menu());
}

bool menu()
{
    gotoxy(2, 1);                                   // ����������
    cout<<"���������� �����:";                      // ������
    gotoxy(50, 1);                                  // �����������
    cout<<"���������� ��������";                    // �����
    for (int i = 0; i<objPtr->getSize(); i++)
    {
        gotoxy(2, 3+i);
        Complex element = objPtr->showStack(i);
        if (objPtr->getCounter()!=0)
        {
            cout<<element;
        }
        else
            cout<<"empty";
    }
    gotoxy(0, 15);
    cout<<"\t1 - ����� �� �����"<<endl
        <<"\t2 - ���� � ����"<<endl
        <<"\t������ ������� - �����"<<endl
        <<"                             "<<endl
        <<"                             "<<endl;
    gotoxy(0, 18);
    while (!_kbhit());                              //                   �������� ������ �������
    int choice;
    choice = _getch();
    switch (choice)
    {
    case TWO:                                       //                                     ����
        {
            Complex object;
            cin>>object;
            objPtr->push(object);
            break;
        }
    case ONE:                                       //                              ��������
        {
            gotoxy(50,3);
            cout<<objPtr->pop()<<endl;
            break;
        }
    default:
        {
            return false;
        }
    }
    return true;
}

void gotoxy(int x, int y)                                           	// ������� ������� � ��������� X,Y
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(hStdOut, coord);
    return;
}