#include <exception>
#include <iostream>

using namespace std;

class MyException : public exception {
public:
    MyException()
    {
    }
    virtual char const* what() const
    {
        return "My custom exception occured";
    }
};

class Test {
public:
    Test()
    {
        throw MyException();
    }
};
int main()
{
    try {
        Test t1;
    } catch (exception& e) {
        cout << " exception caught::" << e.what() << "\n\n";
    }
    return 0;
}
