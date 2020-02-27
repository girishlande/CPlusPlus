#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class A {
public:
    //A() = default;  // comment this line to see the build error 
    A(int a)
    {
    }
};

class B : public A {
public:
    B():A(10) {
        cout << "Default constructor";
    }
};

int main()
{
    B b1; // this will fail if A doesn't have default constructor
    return 0;
}
