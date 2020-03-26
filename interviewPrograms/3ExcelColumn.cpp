#include <iostream>
using namespace std;

// MS Excel columns has a pattern like A, B, C, … ,Z, AA, AB, AC,…. ,AZ, BA, BB, … ZZ, AAA, AAB ….. etc.
// In other words, column 1 is named as "A", column 2 as "B", column 27 as "AA".
// write a function which takes input a column number and returns
// its corresponding Excel column name. Following are more examples.
//
//Input          Output
// 26             Z
// 51             AY
// 52             AZ
// 80             CB
// 676            YZ
// 702            ZZ
// 705            AAC

// write definition for following function declaration
string findColumnNumber(int n);

int main()
{
    cout << "findColumnNumber(26)  " << findColumnNumber(26) << endl;
    cout << "findColumnNumber(51)  " << findColumnNumber(51) << endl;
    cout << "findColumnNumber(52)  " << findColumnNumber(52) << endl;
    cout << "findColumnNumber(80)  " << findColumnNumber(80) << endl;
    cout << "findColumnNumber(676) " << findColumnNumber(676) << endl;
    cout << "findColumnNumber(702) " << findColumnNumber(702) << endl;
    cout << "findColumnNumber(705) " << findColumnNumber(705) << endl;
    return 0;
}

string findColumnNumber(int n)
{
    string output("");

    while (n > 26) {
        int rem = n % 26;
        char ch = 'Z';
        if (rem != 0) {
            ch = 'A' + (rem - 1);
            n = n / 26;
        } else {
            n = n / 26 - 1;
        }
        output += ch;
    }
    char ch = 'Z';
    int rem = n % 26;
    if (rem != 0) {
        ch = 'A' + (rem - 1);
    }
    output += ch;
    std::reverse(output.begin(), output.end());
    return output;
}
