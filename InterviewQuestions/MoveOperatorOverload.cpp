#include <iostream>
#include <map>
#include <vector>
using namespace std;

#define SIZE 250
class Test {
    char* _buffer = { nullptr };

public:
    Test()
    {
    }
    Test(const string& str)
    {
        cout << "Argument constructor called" << endl;
        int len = str.length();
        _buffer = new char[len + 1];
        memcpy(_buffer, str.c_str(), len);
        _buffer[len] = '\0';
    }

    // copy constructor
    Test(const Test& other)
    {
        cout << "Copy constructor called" << endl;
        _buffer = new char[SIZE] {};
        memcpy(_buffer, other._buffer, SIZE);
    }

    // Move constructor
    Test(Test&& other)
    {
        cout << "move constructor called" << endl;
        _buffer = new char[SIZE] {};
        memcpy(_buffer, other._buffer, SIZE);
        other._buffer = nullptr;
    }

    Test& operator=(const Test& other)
    {
        cout << "operator= called" << endl;
        _buffer = new char[SIZE];
        memcpy(_buffer, other._buffer, SIZE);
        return *this;
    }

    Test& operator=(Test&& other)
    {
        cout << "move = operator called" << endl;
        delete[] _buffer;
        _buffer = new char[SIZE];
        memcpy(_buffer, other._buffer, SIZE);
        other._buffer = nullptr;
        return *this;
    }

    char* buffer()
    {
        return _buffer;
    }
    void printBuffer()
    {
        cout << "buffer:" << _buffer << endl;
    }
    ~Test()
    {
        cout << "destructor called " << endl;
        try {
            if (_buffer) {
                delete _buffer;
            }
        } catch (...) {
            cout << "Exception occured while deleting buffer" << endl;
        }
    }
   
};

 Test getTest()
{
    return Test();
}

int main()
{
    Test t1("Girish");
    Test t2;
    t2 = getTest();

    return 0;
}