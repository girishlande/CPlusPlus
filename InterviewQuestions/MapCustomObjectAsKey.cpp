#include <iostream>
#include <list>
#include <map>
#include <vector>
using namespace std;

// Demo of vector

class Person {

private:
    string name;
    int age;

public:
    Person()
    {
    }

    Person(string n, int age)
        : name(n)
        , age(age)
    {
    }

    void print()
    {
        cout << "Person name:" << name << " age:" << age << endl;
    }

    bool operator<(const Person& other) const 
    {
        return name < other.name;
    }
};

int main()
{
    map<Person, int> mmap;
    Person t1("Girish", 33);
    Person t2("Ajit", 44);
    bool ok = t1 < t2;
    cout << "flag: " << ok <<endl;
    mmap.insert({ t1, 55 });
    mmap.insert({ t2, 52 });

    map<Person, int>::iterator it = mmap.begin();
    while (it != mmap.end()) {
        Person p = it->first;
        p.print();
        ++it;
    }

    return 0;
}