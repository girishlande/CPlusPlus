#include <fstream>
#include <iostream>
#include <ostream>

using namespace std;

class MString {

    char* buffer;

public:
    MString()
        : buffer(nullptr)
    {
    }

    MString(const char* b)
    {
        buffer = new char[strlen(b) + 1];
        memcpy(buffer, b, sizeof(char) * (strlen(b) + 1));
    }

    MString(const MString& other)
    {
        buffer = new char[strlen(other.buffer) + 1];
        memcpy(buffer, other.buffer, sizeof(char) * (strlen(other.buffer) + 1));
    }

    MString(MString&& other) {
        this->buffer = other.buffer;
        other.buffer = nullptr;
    }

    MString& operator=(MString&& other) {
        if (&other == this)
            return *this;
        delete this->buffer;
        this->buffer = other.buffer;
        other.buffer = nullptr;
        return *this;
    }

    MString& operator=(const MString& other)
    {
        if (buffer)
            delete[] buffer;
        this->buffer = new char[strlen(other.buffer) + 1];
        memcpy(this->buffer, other.buffer, sizeof(char) * (strlen(other.buffer) + 1));
        return *this;
    }

    ~MString()
    {
        delete[] buffer;
    }
    friend ostream& operator<<(ostream& out, const MString& obj);
};

ostream& operator<<(ostream& out, const MString& obj)
{
    out << string(obj.buffer);
    return out;
}

int main()
{
    // default constructor
    MString str("Girish Lande");
    cout << str << endl;

    // copy constructor
    MString str1 = str;
    cout << str1 << endl;

    // assignment operator 
    MString str2;
    str2 = str1;
    cout << str2 << endl;

    return 0;
}
