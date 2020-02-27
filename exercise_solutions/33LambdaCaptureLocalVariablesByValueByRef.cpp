#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int a = 10;
    int b = 20;
    [=]() {
        cout << "a=" << a << " b=" << b << endl;
    }();

    int c = 30;
    int d = 40;
    [&]() {
        c = 100;
        d = 200;
        cout << "c=" << c << " d=" << d << endl;
    }();

    return 0;
}
