#include <iostream>
#include <list>
#include <map>
#include <vector>
using namespace std;

int main()
{
    multimap<int, int> phoneNo;
    phoneNo.insert({ 1, 9096110103 });
    phoneNo.insert({ 2, 8572392848 });
    phoneNo.insert({ 3, 7464829384 });
    phoneNo.insert({ 1, 8857378392 });
    phoneNo.insert({ 2, 7746278255 });

    multimap<int, int>::iterator it = phoneNo.begin();

    while (it != phoneNo.end()) {
        cout << it->first << " : " << it->second;
    }
    return 0;
}