#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Test {
    int a { 20 };

public:
    Test()
        : Test(10)
    {
    }

    Test(int a)
    {
        this->a = a;
    }

    void print()
    {
        cout << "a=" << a << endl;
    }
};
int main()
{
    Test t1;
    t1.print();

    Test t2(30);
    t2.print();

    return 0;
}
