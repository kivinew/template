/* Разработка шаблона.
Кудрявцев И.В. (поток 09.2015).*/
#pragma once
using namespace std;
template  <typename Type>
class Stack
{
    int size;                                       // размер массива
    Type *array = new Type[size];                   // стек в виде массива
    int top;                                        // вершина стека
    int counter;                                    // счётчик элементов массива (объекта класса Stack)
public:
    Stack(int count);                               // параметр конструктора - это размер стека
    ~Stack();
    int getSize();                                  // 
    void push(Type);
    Type pop();
    Type getElement(int);
    int getCounterElements();
};
template<typename Type>
Stack<Type>::Stack(int count)                       // конструктор стека
{
    top = 0;
    size = count;
}
template<typename Type>
Stack<Type>::~Stack()                               // деструктор
{

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
    return array[--top];
    counter--;
}
template<typename Type>
Type Stack<Type>::getElement(int num)               // отобразить содержимое стека
{   
    return array[num];
}
template<typename Type>
int Stack<Type>::getCounterElements()
{
    return counter;
}
