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
        MyString s1 = "Girish";  // argument constructor
        MyString s2 = s1;  // copy constructor
        MyString s3;  // default constructor
        s3 = std::move(s1);  // move assignment operator 
        MyString s4 = std::move(MyString("Suhas"));  // move constructor 
    }
    cout << endl;
    return 0;
}

// ---------------------------------------------------------------------------
// Example 2 
// ---------------------------------------------------------------------------

class resource {
  int x = 0;
};
class foo
{
  public:
    foo()
      : p{new resource{}}
    { }
    foo(const foo& other)
      : p{new resource{*(other.p)}}
    { }
    foo(foo&& other)
      : p{other.p}
    {
      other.p = nullptr;
    }
    foo& operator=(const foo& other)
    {
      if (&other != this) {
        delete p;
        p = nullptr;
        p = new resource{*(other.p)};
      }
      return *this;
    }
    foo& operator=(foo&& other)
    {
      if (&other != this) {
        delete p;
        p = other.p;
        other.p = nullptr;
      }
      return *this;
    }
    ~foo()
    {
      delete p;
    }
  private:
    resource* p;
};
