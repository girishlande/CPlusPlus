
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Student {
    char* m_name;

public:
    Student() {
        m_name = nullptr;
    }

    Student(const char* name) {
        cout << "\n Student constructor called!";

        int len = strlen(name) + 1;
        m_name = new char[len];
        strcpy_s(m_name, len, name);
    }

    Student(const Student& ref) {
        cout << "\n Student copy constructor called!";
        int len = strlen(ref.m_name) + 1;
        m_name = new char[len];
        strcpy_s(m_name, len, ref.m_name);
    }

    void display() {
        cout << "\n student name:" << m_name;
    }

    ~Student() {
        cout << "\n Student destructor called!";
        if (m_name) {
            delete m_name;
        }
    }
};

int main()
{
    Student s1("Girish");
    s1.display();

    Student s2(s1);
    s2.display();
}

