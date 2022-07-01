
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class A{
    int x = 10;
    static int y;
public:

    A() {
        cout << "\nX:" << x << " Y:" << y;
        x++;
        y++;
    }

    void func() {
        cout << "\nfunc() called! x:" << x << " Y:" << y;
    }

    static void func1(int x1,int y1) {
        cout << "\nstatic func() called! Y:" << y;
        cout << "\n x+y = " << (x1 + y1);
    }
};
int A::y = 10;

int main()
{
    A a1, a2, a3;

    a1.func();
    a2.func();
    a3.func();

    A::func1(10,20);

}

