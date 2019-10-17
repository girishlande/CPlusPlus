#include <iostream>
#include <list>
#include <map>
#include <vector>
using namespace std;

// Demo of vector

int main()
{

    list<int> glist;
    glist.push_back(10);
    glist.push_back(20);
    glist.push_back(30);
    glist.push_back(40);

    list<int>::iterator it = glist.begin();

    int n = 40;
    int cnt = 0;
    while (it != glist.end()) {
        cout << "list element:" << *it << endl;
        if (*it == n) {
            it = glist.erase(it);
        } else {
            it++;
        }
    }

    cout << "\n\nAfter deletion:" << endl;
    it = glist.begin();
    while (it != glist.end()) {
        cout << "list element:" << *it << endl;
        if (*it == n) {
            it = glist.erase(it);
        } else {
            it++;
        }
    }

    return 0;
}