#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
    map<string, int> sids;
    sids.insert(make_pair("Girish", 1232));
    sids.insert(make_pair("ajit", 3232));
    sids.insert(make_pair("suhas", 4323));
    sids.insert(make_pair("sameer", 5324));
    sids.insert(pair<string,int>("rahul", 1111));
    for (auto x : sids) {
        cout << x.first << ":" << x.second << endl;
    }

    if (sids.find("Ajit") != sids.end()) {
        cout << "found element " << endl;
    } else {
        cout << "Did not find element" << endl;
    }

    return 0;
}
