/* Разработка шаблона.*/
#pragma once
#include <iostream>
#include <math.h>
using namespace std;

class Complex
{
    static double const pi;
    static int counter;
    double real, image;
public:
    Complex();
    Complex(double, double);
    Complex(const Complex &);
    ~Complex();
    double mod();
    double arg();
    void show();
    static int getCounter();
    static void del(Complex* &);
    void edit();

    friend ostream & operator << (ostream &out, Complex &obj);
    friend istream & operator >> (istream &in, Complex &obj);
};
