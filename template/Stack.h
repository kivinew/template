/* ���������� �������.
��������� �.�. (����� 09.2015).*/
#pragma once

template  <typename Type>
class Stack
{
    int size;                                       // ������ �������
    Type *array = new Type[size];                   // ���� � ���� �������
    int top;                                        // ������� �����
    int counter;                                    // ������� ������
public:
    Stack(int count=1);                             // �������� ������������ - ��� ������ �����
    ~Stack();
    int getSize();                                  // 
    void push(Type);
    Type pop();
    Type showStack(int);
    int getCounter();
};

template<typename Type>
Stack<Type>::Stack(int count=1)                     // ����������� �����
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
    if (top<=0)
    {
        cout<<"���� ����!"<<endl;
        Type zero();
        return zero;
    }
    return array[--top];
}

template<typename Type>
Type Stack<Type>::showStack(int num)                // ���������� ���������� �����
{   
    if (num<=top)
        return array[num];
}

template<typename Type>
inline int Stack<Type>::getCounter()
{
    return counter;
}
