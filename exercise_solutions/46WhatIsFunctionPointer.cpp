#include <iostream>
#include <map>
#include <vector>
using namespace std;

// call functions using function pointers
// Function pointer, also called a subroutine pointer or procedure pointer, 
// is a pointer that points to a function. As opposed to referencing a data value, 
// a function pointer points to executable code within memory.
void func1()
{
    cout << "func1 called" << endl;
}
void func2()
{
    cout << "func2 called" << endl;
}
void func3()
{
    cout << "func3 called" << endl;
}
int factorial(int f)
{
    if (f == 1)
        return 1;
    else
        return f * factorial(f - 1);
}

int main()
{
    void (*fptr[3])();
    fptr[0] = func1;
    fptr[1] = func2;
    fptr[2] = func3;
    for (int i = 0; i < 3; i++) {
        fptr[i]();
    }

    int (*factorialFunctionPtr)(int) = factorial;
    int n;
    cout << "Enter number:";
    cin >> n;
    cout << "Factorial is:" << factorialFunctionPtr(n) <<endl;

    return 0;
}