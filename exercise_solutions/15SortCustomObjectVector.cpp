#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Student {
    int m_roll;
    string m_name;

public:
    Student(int roll, string name)
        : m_roll(roll)
        , m_name(name)
    {
    }

    void print() {
        cout << "roll:" << m_roll << " name:" << m_name << endl;
    }

    bool operator<(const Student& s) const {
        return m_roll < s.m_roll;
    }
};

int main()
{
    vector<Student> studs;
    studs.push_back(Student(20, "Girish"));
    studs.push_back(Student(40, "Ajit"));
    studs.push_back(Student(10, "Suhas"));
    studs.push_back(Student(30, "sameer"));

    sort(studs.begin(), studs.end());
    for (auto x : studs) {
        x.print();
    }
    return 0;
}
