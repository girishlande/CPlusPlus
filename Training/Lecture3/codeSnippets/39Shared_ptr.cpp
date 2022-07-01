#include <algorithm>
#include <iostream>
#include <map>
#include <memory>
#include <vector>
using namespace std;

class Test {
public:
    Test()
    {
        cout << "Test constructor" << endl;
    }

    ~Test()
    {
        cout << "Test destructor" << endl;
    }
};

int main()
{
    shared_ptr<Test> t1(new Test());
    {
        cout << "reference count :" << t1.use_count() << endl;
        shared_ptr<Test> t2 = t1;
        cout << "reference count :" << t2.use_count() << endl;
        shared_ptr<Test> t3 = t2;
        cout << "reference count :" << t3.use_count() << endl;
        t1 = t3;
        cout << "reference count :" << t1.use_count() << endl;
    }
    cout << "reference count :" << t1.use_count() << endl;

    return 0;
}
