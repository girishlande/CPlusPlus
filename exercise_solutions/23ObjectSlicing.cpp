#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class A {
    int a = 10;

public:
    A()
    {
        cout << "A constructor" << endl;
    }
    ~A()
    {
        cout << "A destructor" << endl;
    }
    A(const A& other) {
        a = other.a;
        cout << "A Copy constructor" << endl;
    }
    virtual void print() {
        cout << "A print:" << a <<endl;
    }
};

class B : public A {
    int b = 20;

public:
    B() {
        cout << "B constructor" << endl;
    }
    ~B() {
        cout << "B destructor" << endl;
    }

    void print() {
        cout << "B print:" << b << endl;
    }
};

int main()
{
    B b1;
    A a1 = b1;
    a1.print();

    return 0;
}
