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
    Test(string str)
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

int main()
{
    string name("Girish");

    vector<Test> vec;
    vec.push_back(Test(name));

    return 0;
}