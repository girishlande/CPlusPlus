#include <iostream>
using namespace std;

// write a program to print all prime numbers between given 2 numbers.
// for e.g 
// printPrimeNumbers(10, 20)
// output:
// Prime numbers between 10 and 20 are 11, 13, 17, 19,

// write definition of following function declaration
void printPrimeNumbers(int a, int b);

int main()
{
    printPrimeNumbers(10, 20);
    cout << endl;
    return 0;
}

void printPrimeNumbers(int a, int b)
{
    cout << "Prime numbers between "<< a << " and " << b << " are ";
    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }
    for (int i = a; i < b; i++) {
        bool flag = true;
        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << i << ", ";
        }
    }
}