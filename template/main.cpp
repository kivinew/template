/* Лабораторная работа №4. Разработка шаблона.
Кудрявцев И.В. (поток 09.2015).
Вариант №9: стек (размер - параметр конструктора).*/

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
    cout<<"Размер стека: ";
    cin>>stackSize;
    Stack<Complex> obj(stackSize);
    objPtr = &obj;
    while(menu());
}

bool menu()
{
    gotoxy(0, 1);                                   // оформление
    cout<<"Содержимое стека:";                      // вывода
    gotoxy(50, 1);                                  // содержимого
    cout<<"Полученное значение";                    // стека
                                                    //
    int elemCount = objPtr->getCounterElements();   // 
    if (elemCount>0)                                //
    {                                               //
        for (int i = 0; i<elemCount; i++)           //
        {                                           //
            gotoxy(0, 3+i);                         //
            Complex element = objPtr->showStack(i); //
                                                    //
            //cout<<element;                        // ОШИБКА!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        }
    }

    gotoxy(0, 15);
    cout<<"\t1 - вывод из стека"<<endl
        <<"\t2 - ввод в стек"<<endl
        <<"\tДругие клавиши - выход"<<endl
        <<"                             "<<endl
        <<"                             "<<endl;
    gotoxy(0, 18);
    while (!_kbhit());                              //                   ожидание выбора клавиши
    int choice;
    choice = _getch();
    switch (choice)
    {
    case TWO:                                       //                                     ввод
        {
            Complex object;
            cin>>object;
            objPtr->push(object);
            break;
        }
    case ONE:                                       //                              удаление
        {
            gotoxy(50,3);
            if (elemCount!=0)
                cout<<objPtr->pop()<<endl;
            else
                cout<<"Стек пуст!"<<endl;
            break;
        }
    default:
        {
            return false;
        }
    }
    return true;
}

void gotoxy(int x, int y)                                           	// перевод курсора в положение X,Y
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(hStdOut, coord);
    return;
}