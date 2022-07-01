
#include <iostream>

using namespace std;

bool isPrime(int n) {
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

bool  isEven(int n) {
    return n % 2 == 0;
}

int main()
{
    int n = 11;

    bool (*fptr)(int);
    fptr = isPrime;

    int choice;
    cout << "Enter choice: 1. Prime number check  2. Even number check ";
    cin >> choice;

    if (choice == 2) {
        fptr = isEven;
    }
    bool flag = fptr(n);   // function call 
    cout << "\n Check output:" << flag;
}

