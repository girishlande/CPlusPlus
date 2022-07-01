#include <algorithm>
#include <iostream>
#include <vector>
#include<memory>
using namespace std;

class Test {
    int data;

public:
    Test()
    {
        data = 10;
        cout << "Test constructor" << endl;
    }
    ~Test()
    {
        cout << "Test destructor" << endl;
    }
    void print()
    {
        cout << endl
             << "Test data:" << data << endl;
    }
};

void display(Test* t)
{
    t->print();
}

class Temp {
    unique_ptr<Test> m_test;

public:
    Temp() {

    }
};

int main()
{
    unique_ptr<Test[]> t1(new Test[4]);
    auto_ptr<Test> t2(new Test());
    display(t2.get());

    return 0;
}
