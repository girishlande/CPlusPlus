#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Test {

public:
    virtual bool operator()(string str)
    {
        return str.length() == 3;
    }
};

class stringTest : public Test {
public:
    bool operator()(string str)
    {
        return str.length() == 5;
    }
};

void check(Test& test, string arg)
{
    cout<< "check:" << arg << ":" << test(arg) << endl;
}

int main()
{
    string str("gir");
    string str1("ajitt");

    Test test3;
    stringTest test5;
    check(test3, str);
    check(test5, str);
    check(test3, str1);
    check(test5, str1);

    cout << endl;

    return 0;
}
