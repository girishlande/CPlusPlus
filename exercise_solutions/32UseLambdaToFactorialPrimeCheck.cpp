#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    auto fact = []() {
        int n;
        cout << "Enter number:";
        cin >> n;
        int f = 1;
        for (int i = 1; i <= n; i++) {
            f *= i;
        }
        return f;
    };

    cout << "factorial : " << fact() << endl;

    auto factn = [](int n) {
        int f = 1;
        for (int i = 2; i <= n; i++)
            f *= i;
        return f;
    };
    cout << "Factorial of 4 is:" << factn(4) <<endl;

    auto prime = []() {
        int n;
        cout << "Enter number:";
        cin >> n;
        for (int i = 2; i < n; i++)
            if (n % i == 0)
                return false;
        return true;
    };
    cout << "Number is prime :" << prime() <<endl;

    auto primen = [](int n) {
        for (int i = 2; i < n; i++)
            if (n % i == 0)
                return false;
        return true;
    };
    cout << "Number is prime :" << primen(11) << endl;

    return 0;
}
