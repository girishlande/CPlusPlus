#include <exception>
#include <iostream>
#include <vector>
using namespace std;

class Test {
    char* buffer;

public:
    Test()
    {
        buffer = new char[999999999];
    }
};

int main()
{
    try {
        for (int i = 0; i < 100; i++) {
            Test* t1 = new Test();
        }
    } catch (bad_alloc e) {
        cout << "memory allocation exception caught:" << e.what() << endl;
    }
    cout << "finished successfully\n" << endl;

    return 0;
}
