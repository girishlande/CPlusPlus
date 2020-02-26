#include <algorithm>
#include <iostream>
#include <ostream>
using namespace std;

class Student {
    int m_roll;
    string m_name;

public:
    Student() {}

    Student(int roll, string name)
        : m_roll(roll)
        , m_name(name)
    {
    }

    Student(const Student& s) {
        cout << "copy constructor called\n";
        m_name = s.m_name;
        m_roll = s.m_roll;
    }

    void print()
    {
        cout << "roll:" << m_roll << " name:" << m_name << endl;
    }

    Student& operator=(const Student& other) {
        cout << "=operator called\n";
        m_roll = other.m_roll;
        m_name = other.m_name;
        return *this;
    }

    friend ostream& operator << (ostream& out, const Student& other);
};

ostream& operator<<(ostream& out, const Student& other)
{
    out << "Student roll:" << other.m_roll << "name:" << other.m_name;
    return out;
}

int main()
{
    Student s1(11, "Girish");
    Student s2(12, "Suhas");
    Student s3 = s1 = s2;

    cout << s1 << endl
         << s2 << endl
         << s3 << endl;

    return 0;
}
