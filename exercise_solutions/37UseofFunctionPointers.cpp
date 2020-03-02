#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int n)
{
    bool prime = true;
    for (int i = 2; i < n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

bool isEven(int n)
{
    return n % 2 == 0;
}

void performCheck(const string& testname, bool (*func)(int), int n)
{
    cout << endl << testname << endl;
    if (func(n)) {
        cout << "Passed!!" << endl;
    } else {
        cout << "Failed!!" << endl;
    }
}

int main()
{
    int n = 5;

    bool (*func)(int n);

    performCheck("Check if number is prime", isPrime, 5);
    performCheck("Check if number is Even", isEven, 5);


    return 0;
}
