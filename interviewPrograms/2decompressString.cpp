#include <iostream>
#include <mutex>
#include <shared_mutex>
#include <sstream>
#include <thread>
#include <vector>
using namespace std;

// Write a program to decompress a string. Input string has for <char><frequency><char><frequency>..
// example:
// input : a3d5w3b10c20d30
// output : aaadddddwwwbbbbbbbbbbccccccccccccccccccccdddddddddddddddddddddddddddddd

// write definition for following function declaration
string decompressString(string in);

int main()
{
    string encrypted("a3d5w3b10c20d30");
    cout << "input:" << encrypted << endl
         << "output:" << decompressString(encrypted) << endl
         << endl;
    return 0;
}

string decompressString(string in)
{
    string de;
    int i = 0;
    stringstream output;
    while (i < in.length()) {
        char c = in[i];
        int j = i + 1;
        stringstream stream;
        while (j < in.length() && in[j] >= '0' && in[j] <= '9') {
            stream << in[j];
            j++;
        }
        int num = 0;
        stream >> num;
        output << string(num, c);
        i = j;
    }
    return output.str();
}