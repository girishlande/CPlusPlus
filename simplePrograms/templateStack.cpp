// exceptionTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <fstream>
#include <iostream>
#include <list>
#include <set>
#include <string>
#include <vector>
using namespace std;

class Student {
    int roll;
    string name;

public:
    Student() {}
    Student(int r, string n)
        : roll(r)
        , name(n)
    {
    }

    void print()
    {
        cout << "roll:" << roll << " name:" << name << endl;
    }
};

template <class T>
class MStack {
    int m_top = -1;
    vector<T> m_items;

public:
    MStack()
        : m_top(-1)
    {
    }

    void push(const T& obj)
    {
        m_items.push_back(obj);
    }

    T pop()
    {
        T obj = m_items.at(m_items.size() - 1);
        m_items.pop_back();
        return obj;
    }

    T& get(int i)
    {
        return m_items.at(i);
    }

    bool isEmpty()
    {
        return m_items.size() == 0;
    }
};

int main()
{
    MStack<int> stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);

    while (!stack.isEmpty())
        cout << stack.pop() << endl;

    MStack<Student> s;
    s.push(Student(1, "Girish"));
    s.push(Student(2, "Ajit"));
    s.push(Student(3, "Suhas"));
    s.push(Student(4, "Sameer"));

    for (int i = 0; i < 4; i++) {
        Student ss = s.get(i);
        ss.print();
    }
    while (!s.isEmpty()) {
        Student ss = s.pop();
        ss.print();
    }

    return 0;
}
