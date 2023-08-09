// ConsoleApplication14.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <set>
using namespace std;

void printCombinations(set<string>& v, int level) {
    if (level == 1)
        return;
    level--;
    set<string> output;
    for (string s:v) {
        // Append
        string s1 = s + "()";
        output.insert(s1);

        // Prepend
        string s2 = "()" + s;
        output.insert(s2);

        // wrap version 
        string s3 = "(" + s + ")";
        output.insert(s3);
    }
    v = output;
    printCombinations(v, level);
}

int main()
{
    string s = "()";

    for (int n = 1; n <= 6; n++) {
        cout << endl << n << ":";
        set<string> v;
        v.insert(s);
        printCombinations(v, n);
        cout << v.size() << " ";
        for (auto a : v) {
            cout << a << ",";
        }
    }

    cout << "\n\n";
}

