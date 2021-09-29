#include <iostream>
#include <list>
#include <map>
#include <vector>
using namespace std;

int main()
{
    multimap<int, int> phoneNo;
    phoneNo.insert({ 1, 11 });
    phoneNo.insert({ 2, 22 });
    phoneNo.insert({ 3, 33 });
    phoneNo.insert({ 1, 12 });
    phoneNo.insert({ 2, 23 });

    multimap<int, int>::iterator it = phoneNo.begin();

    while (it != phoneNo.end()) {
        cout << it->first << " : " << it->second <<endl;
        ++it;
    }
    return 0;
}