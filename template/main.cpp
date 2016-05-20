/* ������������ ������ �4. ���������� �������.
��������� �.�. (����� 09.2015).
������� �9: ���� (������ - �������� ������������).*/

#include "Stack.h"
#include "Complex.h"

#define ONE         49
#define TWO         50
#define THREE       51
#define FOUR        52

bool menu();
void gotoxy(int, int);

Stack<Complex> *objPtr=NULL;

int main()
{
    setlocale(LC_ALL, "Russian");
    int stackSize;
    cout<<"������ �����: ";
    cin>>stackSize;
    Stack<Complex> obj(stackSize);
    objPtr = &obj;
    while(menu());
}

bool menu()
{
    gotoxy(0, 1);                                   // ����������
    cout<<"���������� �����:";                      // ������
    gotoxy(50, 1);                                  // �����������
    cout<<"���������� ��������";                    // �����
                                                    //
    int elemCount = objPtr->getCounterElements();   // 
    if (elemCount>0)                                //
    {                                               //
        for (int i = 0; i<elemCount; i++)           //
        {                                           //
            gotoxy(0, 3+i);                         //
            Complex element = objPtr->showStack(i); //
                                                    //
            //cout<<element;                        // ������!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        }
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
            if (elemCount!=0)
                cout<<objPtr->pop()<<endl;
            else
                cout<<"���� ����!"<<endl;
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