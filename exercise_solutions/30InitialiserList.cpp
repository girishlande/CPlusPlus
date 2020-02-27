#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Test {
    vector<string> items;

public:
    Test(initializer_list<string> list)
    {
        for (auto x : list) {
            cout << x << endl;
            items.push_back(x);
        }
    }

    void print()
    {
        cout << "\n\nMember items:" << endl;
        for (auto x : items)
            cout << x << endl;
    }
};

int main()
{
    Test t1 = { "Girish",
        "Ajit",
        "Suhas",
        "Ramesh" };

    t1.print();

    cout << endl;

    return 0;
}
