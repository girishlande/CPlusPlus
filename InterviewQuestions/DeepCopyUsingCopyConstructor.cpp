#include <iostream>
#include <map>
#include <vector>
using namespace std;

// If we don't write our own copy constructor then by default provided copy constructor by compiler will do shallow copying
// Deep copy in copy constructor 
#define SIZE 250
class Test {
    char* _buffer = { nullptr };

public:
    Test()
    {
    }
    Test(string str)
    {
        int len = str.length();
        _buffer = new char[len + 1];
        memcpy(_buffer, str.c_str(), len);
        _buffer[len] = '\0';
    }
    Test(const Test& other)
    {
        _buffer = new char[SIZE] {};
        memcpy(_buffer, other._buffer, SIZE);
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
        try {
            cout << "deleting buffer" << endl;
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
    Test t1(name);
    t1.printBuffer();

    Test t2(t1);
    t2.printBuffer();

    return 0;
}