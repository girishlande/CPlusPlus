#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Test {
    int n { 3 };

public:
    Test() = delete;
    Test(int n)
        : n(n)
    {
    }
    Test(const Test& other) = delete;
    Test& operator=(const Test& other) = delete;

    void print()
    {
        cout << "Hello Test! " << n << endl;
    }
};
int main()
{
    Test t1(10);
    t1.print();

    /*Test t4(20);
    t4.print();
    t4 = t1;
    t4.print();*/

    /*Test t2 = t1;
    t2.print();*/

    //Test t3;
    //t3.print();

    return 0;
}
