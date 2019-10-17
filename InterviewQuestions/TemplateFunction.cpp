#include <iostream>
#include <map>
#include <vector>
using namespace std;

// what is template function 
template <class T>
T gmax(T x, T y)
{
    if (x > y)
        return x;
    return y;
}

int main()
{
    cout << gmax(10, 20) << endl;
    cout << gmax('A', 'F') << endl;
    cout << gmax(23.23, 20.22) << endl;

    return 0;
}