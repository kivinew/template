/* Разработка шаблона.*/
#include "comPlex.h"

int Complex::counter;
double const Complex::pi = 3.1415926536;

Complex::Complex(): real(0.), image(0.)                                         // конструктор по умолчанию
{
    counter++;
}

Complex::Complex(double re, double im): real(re), image(im)                     // конструктор с параметрами
{
    counter++;
}

Complex::Complex(const Complex &obj): real(obj.real), image(obj.image)          // конструктор копирования
{
    counter++;
}

Complex::~Complex()                                                             // деструктор
{
    counter--;
}

int Complex::getCounter()                                                       // возврат счётчика
{
    return counter;
}

void Complex::edit()                                                    // редактирование объекта
{
    cin>>*this;
    return;
}

void Complex::del(Complex* &obj)                                        // удаление объекта
{
    if (obj!=NULL)
    {
        delete obj;
        obj = NULL;
    }
    return;
}

void Complex::showObject()                                              // вывод объекта
{
    cout<<"Z="<<real<<"+"<<image<<"*i"<<"\t"<<"|Z|="<<mod()<<"\t";
    if (arg()!=0)
        cout<<"arg Z="<<arg()*180/pi<<"\t"<<endl;
    else
        cout<<"n/a"<<endl;
    return;
}

double Complex::mod()                                                   // модуль |Z|
{
    return sqrt(real*real+image*image);
}

double Complex::arg()                                                   // аргумент arg Z
{
    if (real>0) return atan(image/real);
    if (real<0)
    {
        if (image>0) return pi+atan(image/real);
        if (image<0) return -pi+atan(image/real);
        if (image==0) return pi;
    }
    if (real==0)
    {
        if (image>0) return pi/2;
        if (image<0) return -pi/2;
    }
    return 0;
}

ostream & operator << (ostream &out, Complex &obj)                              // cout<<
{
    out<<"Z = "<<obj.real<<" + "<<obj.image<<"i      ";
    return out;
}

istream & operator >> (istream &in, Complex &obj)                                 // cin>>
{
    cout<<"Введите real =     \b\b\b\b";
    in>>obj.real;
    cout<<"Введите image =     \b\b\b\b";
    in>>obj.image;
    return in;
}
