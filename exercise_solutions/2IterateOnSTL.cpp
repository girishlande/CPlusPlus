#include <iostream>
#include <list>
#include <map>
#include <set>
#include <vector>
using namespace std;

int main()
{
    vector<string> vecString;
    vecString.push_back("Girish");
    vecString.push_back("Ajit");
    vecString.push_back("Sameer");
    vecString.push_back("Suhas");

    cout << "String vector content:" << endl;
    for (auto x : vecString) {
        cout << x << ",";
    }

    cout << "\n\nInteger list content:" << endl;
    list<int> list_numbers;
    list_numbers.push_back(10);
    list_numbers.push_back(20);
    list_numbers.push_back(30);
    list_numbers.push_back(40);
    for (auto x : list_numbers) {
        cout << x << ",";
    }

    cout << "\n\n string character content:" << endl;
    string mylongString("Hi This is very long string");
    for (auto x : mylongString) {
        cout << x << " ";
    }

    cout << "\n\n map(int,string) content:" << endl;
    map<int, string> intStringMap;
    intStringMap.insert(make_pair(1, "Girish"));
    intStringMap.insert(make_pair(2, "Ajit"));
    intStringMap.insert(make_pair(3, "Suhas"));
    intStringMap.insert(make_pair(4, "Sameer"));
    for (auto x : intStringMap) {
        cout << x.first << "->" << x.second << endl;
    }

    set<int> set_numbers;
    cout << "\n\n Contents of set:" << endl;
    set_numbers.insert(20);
    set_numbers.insert(40);
    set_numbers.insert(10);
    set_numbers.insert(30);
    for (auto x : set_numbers) {
        cout << x << "  ";
    }
    cout << endl;
    cout << endl;

    return 0;
}
