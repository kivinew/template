/* Разработка шаблона.
Кудрявцев И.В. (поток 09.2015).*/
#pragma once

template  <typename Type>
class Stack
{
    int size;                                       // размер массива
    Type *array = new Type[size];                   // стек в виде массива
    int top;                                        // вершина стека
    int counter;                                    // счётчик стеков
public:
    Stack(int count=1);                             // параметр конструктора - это размер стека
    ~Stack();
    int getSize();                                  // 
    void push(Type);
    Type pop();
    Type showStack(int);
    int getCounter();
};

template<typename Type>
Stack<Type>::Stack(int count=1)                     // конструктор стека
{
    top = 0;
    size = count;
}

template<typename Type>
Stack<Type>::~Stack()                               // деструктор
{
    delete array;
    cout<<"Stack destructor: "<<counter<<endl;
}

template<typename Type>
int Stack<Type>::getSize()                          // размер стека
{
    return size;
}

template<typename Type>
void Stack<Type>::push(Type value)                  // положить в стек
{
    if (top>=size)
    {
        cout<<"Переполнение стека!"<<endl;
        return;
    }
    array[top++] = value;
    counter++;
}

template<typename Type>
Type Stack<Type>::pop()                             // взять из стека
{
    if (top<=0)
    {
        cout<<"Стек пуст!"<<endl;
        Type zero();
        return zero;
    }
    return array[--top];
}

template<typename Type>
Type Stack<Type>::showStack(int num)                // отобразить содержимое стека
{   
    if (num<=top)
        return array[num];
}

template<typename Type>
inline int Stack<Type>::getCounter()
{
    return counter;
}
