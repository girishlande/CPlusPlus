#include <iostream>
using namespace std;

int factorial(int n)
{
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int isPrime(int n)
{
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

int main()
{
    int n = 5;

    int (*f)(int) = factorial;
    cout << "factorial of " << n << " is " << f(5) << endl;

    f = isPrime;
    cout << "Is this prime number :" << f(5) << endl;
    cout << "Is this prime number :" << f(15) << endl;

    bool (*fn)(int n) = isEven;
    cout << "Is this even number:" << fn(12) << endl;
    cout << "Is this even number:" << fn(13) << endl;

    cout << endl;
    cout << endl;
    return 0;
}
