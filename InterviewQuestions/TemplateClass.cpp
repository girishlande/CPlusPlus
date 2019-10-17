#include <iostream>
#include <map>
#include <vector>
using namespace std;
#define MAXSIZE 5

// What is Template class and how its useful ?
// Templates are a feature of the C++ programming language that allows functions and 
// classes to operate with generic types. This allows a function or class to work on many 
// different data types without being rewritten for each one.

template <class T>
class GStack {
    int top = -1;
    T data[MAXSIZE];

public:
    void push(T value)
    {
        if (isFull()) {
            cout << " Stack is Full" << endl;
            return;
        }
        data[++top] = value;
    }
    T pop()
    {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            top = 0;
        }
        return data[top--];
    }
    bool isEmpty()
    {
        return top == -1;
    }
    bool isFull()
    {
        return top == MAXSIZE - 1;
    }
};

int main()
{
    GStack<int> gstack;
    gstack.push(10);
    gstack.push(20);
    gstack.push(30);
    gstack.push(40);
    gstack.push(50);
    gstack.push(60);

    cout << "Stack contents:" << endl;
    while (!gstack.isEmpty())
    {
        cout << gstack.pop() << endl;
    }

    GStack<string> stringStack;
    stringStack.push("Girish");
    stringStack.push("Ajit");
    stringStack.push("Suhas");
    stringStack.push("Sameer");
    cout << "\nStack contents:" << endl;
    while (!stringStack.isEmpty()) {
        cout << stringStack.pop() << endl;
    }

    return 0;
}