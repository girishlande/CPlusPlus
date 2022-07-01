// ConsoleApplication6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include<list>
#include<set>
#include<algorithm>
#include<deque>
#include<map>

using namespace std;

int main()
{
    vector<int> vec;

    multiset<int> s;
    s.insert(30);
    s.insert(20);
    s.insert(10);
    s.insert(10);
    s.insert(10);
    for (auto a : s) {
        cout << a << " ";
    }

    cout << "\n";


    multiset<int> s1;
    
    multimap<int, string> m;
    m.insert({ 3,"Sameer" });
    m.insert({ 4,"Ajit" });
    m.insert({ 2,"Suhas" });
    m.insert({ 1,"girish" });
    m.insert({ 2,"Rahul" });
    m.insert({ 1,"Sachin" });

    for (auto a : m) {
        cout << "\n " << a.first << "=>" << a.second;
    }

    // time complexity : O(1) very good
    int x = 10;
    int y = 20;
    int z = x + y;
    int n = 10000000;


    // time complexity : O(n) OR   linear   good
    for (int i = 0; i < n; i++) {
        // so some operation 
        // statement 1
        // statement 2
    }

    // time complexity : O(n^2) 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
        // so some operation 
        // statement 1
        // statement 2
    }

}

