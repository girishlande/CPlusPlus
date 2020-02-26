#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;
class MyString {

    char* m_buffer;

public:
    MyString()
        : m_buffer(nullptr)
    {
        cout << "\ndefault constructor";
    }

    MyString(const char* buffer)
    {
        cout << "\nargument constructor";
        size_t len = strlen(buffer);
        this->m_buffer = new char[len + 1];
        memcpy(this->m_buffer, buffer, len + 1);
    }

    MyString(const MyString& other)
    {
        cout << "\ncopy constructor";
        size_t len = strlen(other.m_buffer);
        this->m_buffer = new char[len + 1];
        memcpy(this->m_buffer, other.m_buffer, len + 1);
    }

    MyString& operator=(const MyString& other)
    {
        cout << "\n operator=";
        if (this->m_buffer) {
            delete[] this->m_buffer;
        }
        size_t len = strlen(other.m_buffer);
        this->m_buffer = new char[len + 1];
        memcpy(this->m_buffer, other.m_buffer, len + 1);
        return *this;
    }

    MyString(MyString&& other)
    {
        cout << "\n Move constructor";
        if (this->m_buffer) {
            delete[] this->m_buffer;
        }
        this->m_buffer = other.m_buffer;
        other.m_buffer = nullptr;
    }

    MyString& operator=(MyString&& other)
    {
        cout << "\n move assignment operator";
        if (this->m_buffer)
            delete[] this->m_buffer;
        this->m_buffer = other.m_buffer;
        other.m_buffer = nullptr;
        return *this;
    }

    void print()
    {
        cout << "\nString:" << m_buffer;
    }

    ~MyString()
    {
        cout << "\ndestructor";
        if (m_buffer) {
            delete[] m_buffer;
        }
    }
};

int main()
{
    {
        MyString s1 = "Girish";
        MyString s2 = s1;
        MyString s3;
        s3 = std::move(s1);
        MyString s4 = std::move(MyString("Suhas"));
    }
    cout << endl;
    return 0;
}
