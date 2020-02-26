#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
    vector<int> vec;
    map<string, vector<int>> map;
    map.insert(make_pair(string("Girish"), vec));
    map.insert(make_pair(string("Ajit"), vec));
    map.insert(make_pair(string("Suhas"), vec));

    for (auto &x : map) {
        vector<int> &v = x.second;
        v.push_back(rand()%10);
        v.push_back(rand() % 10);
        v.push_back(rand() % 10);
    }

    for (auto x : map) {
        vector<int> v = x.second;
        cout << endl<< x.first << " : ";
        for (auto y : v) {
            cout << y << "  ";
        }
    }

    cout << endl;
    cout << endl;

    return 0;
}
