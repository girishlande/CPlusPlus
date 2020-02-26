#include <iostream>
#include <map>

using namespace std;
class Student {
    int mroll;
    string mname;

public:
    Student(int roll, string name)
        : mroll(roll)
        , mname(name)
    {
    }

    int roll()
    {
        return mroll;
    }
    string name()
    {
        return mname;
    }
    bool operator<(const Student& other) const {
        return this->mroll < other.mroll && this->mname<other.mname;
    }
};
int main()
{
    map<Student, int> studId;
    studId.insert(make_pair(Student(1,"ajit"), 1));
    studId.insert(make_pair(Student(2, "girish"), 2));
    studId.insert(make_pair(Student(3, "suhas"), 3));
    studId.insert(make_pair(Student(4, "sameer"), 4));

    if (studId.find(Student(11, "rahul")) != studId.end()) {
        cout << "found element" << endl;
    } else {
        cout << "Didnt find element" << endl;
    }

    return 0;
}
