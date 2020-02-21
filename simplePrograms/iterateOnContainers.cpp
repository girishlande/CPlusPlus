// exceptionTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <fstream>
#include <iostream>
#include <list>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

int main()
{
    vector<string> names;
    names.push_back("Girish");
    names.push_back("Ajit");
    names.push_back("Suhas");
    names.push_back("Sameer");
    for (auto x : names) {
        cout << x << endl;
    }

    cout << endl;
    set<string> setnames;
    setnames.insert("Girish");
    setnames.insert("Ajit");
    setnames.insert("Suhas");
    setnames.insert("Girish");
    setnames.insert("Ajit");
    setnames.insert("Suhas");
    setnames.insert("Jiwan");
    for (auto x : setnames) {
        cout << x << endl;
    }

    cout << endl;
    list<string> listnames;
    listnames.push_back("Girish");
    listnames.push_back("Ajit");
    listnames.push_back("Suhas");
    listnames.push_back("Jiwan");
    for (auto x : listnames) {
        cout << x << endl;
    }

    cout << endl;
    unordered_set<int> us;
    us.insert(10);
    us.insert(20);
    us.insert(30);
    us.insert(0);
    us.insert(50);
    us.insert(40);
    for (auto x : us) {
        cout << x << endl;
    }

    return 0;
}
