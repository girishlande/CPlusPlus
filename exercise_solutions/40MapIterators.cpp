#include <algorithm>
#include <iostream>
#include <map>
#include <memory>
#include <vector>
using namespace std;

int main()
{
    map<int, string> m;
    m.insert(make_pair(2, "Ajit"));
    m.insert(make_pair(5, "Rahul"));
    m.insert(make_pair(3, "Suhas"));
    m.insert(pair<int, string>(1, "Girish"));
    m.insert(make_pair(4, "Sameer"));
    for (auto x : m) {
        cout << x.first << ":" << x.second << endl;
    }

    // Iterate using iterators 
    cout << "\nIterators\n";
    for (auto it = m.begin(); it != m.end(); ++it) {
        cout << it->first << "=" << it->second << endl;
    }

    map<string, int> n;
    n.insert(make_pair("Ajit", 1));
    n.insert(make_pair("Suhas", 2));
    n.insert(make_pair("Babli", 3));
    n.insert(make_pair("Chikara", 4));
    n.insert(make_pair("Ramdev", 5));
    n.insert(make_pair("Deepak", 5));
    cout << "\n String->int" << endl;
    for (auto x : n) {
        cout << x.first << ":" << x.second << endl;
    }

    return 0;
}

