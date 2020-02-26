#include <iostream>
#include <map>
#include <set>
#include <unordered_set>

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

    void print()
    {
        cout << "\n Roll:" << mroll << " name:" << mname;
    }

    bool operator<(const Student& other) const {
        return mroll < other.mroll;
    }
};

int main()
{
    Student s1(1, "Girish");
    Student s2(2, "Ajit");
    Student s3(3, "Suhas");

    cout << "\n\n";
    map<Student, int> smap;
    smap.insert(make_pair(s1, 11));
    smap.insert(make_pair(s2, 22));
    smap.insert(make_pair(s3, 33));
    for (auto x : smap) {
        Student s = x.first;
        s.print();
    }

    cout << "\n\nUnordered set:" << endl;
    unordered_set<int> uset;
    uset.insert(40);
    uset.insert(10);
    uset.insert(30);
    uset.insert(20);
    for (auto x : uset) {
        cout << "x:" << x << endl;
    }

    cout << "\nordered set:" << endl;
    set<int> mset;
    mset.insert(40);
    mset.insert(10);
    mset.insert(30);
    mset.insert(20);
    for (auto x : mset) {
        cout << "x:" << x << endl;
    }

    return 0;
}
