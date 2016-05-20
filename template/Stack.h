/* ���������� �������.
��������� �.�. (����� 09.2015).*/
#pragma once
#include <iostream>
#include <clocale>
#include <Windows.h>
using namespace std;

template  <typename Type>
class Stack
{
    int size;                                       // ������ �������
    Type *array = new Type[size];                   // ���� � ���� �������
    int top;                                        // ������� �����
    int counter;                                    // ������� ������
public:
    Stack(int count);                               // �������� ������������ - ��� ������ �����
    ~Stack();
    int getSize();                                  // 
    void push(Type);
    Type pop();
    Type showStack(int);
    int getCounterElements();
};

template<typename Type>
Stack<Type>::Stack(int count)                       // ����������� �����
{
    top = 0;
    size = count;
}

template<typename Type>
Stack<Type>::~Stack()                               // ����������
{
    delete array;
    cout<<"Stack destructor: "<<counter<<endl;
}

template<typename Type>
int Stack<Type>::getSize()                          // ������ �����
{
    return size;
}

template<typename Type>
void Stack<Type>::push(Type value)                  // �������� � ����
{
    if (top>=size)
    {
        cout<<"������������ �����!"<<endl;
        return;
    }
    array[top++] = value;
    counter++;
}

template<typename Type>
Type Stack<Type>::pop()                             // ����� �� �����
{
    return array[--top];
}

template<typename Type>
Type Stack<Type>::showStack(int num)                // ���������� ���������� �����
{   
    return array[num];
}

template<typename Type>
inline int Stack<Type>::getCounterElements()
{
    return counter;
}
