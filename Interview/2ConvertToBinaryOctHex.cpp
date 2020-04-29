#include <QCoreApplication>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <fstream>
using namespace std;

string toString(int n) {
    vector<char> output;
    if (n>=0 && n<10) {
        output.push_back(48+n);
    } else {
        output.push_back(55+n);
    }
    return string(output.begin(),output.end());
}

void convertToBase(int base,int decimal) {
    string output;

    while(decimal!=0) {
        int rem = decimal%base;
        output += toString(rem);
        decimal = decimal / base;
    }
    reverse(output.begin(),output.end());
    cout << "base:" << base << " :" << output;
}

// Program to convert deciman to binary, octal and hex
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int number;
    int base;
    cout<<"Enter decimal number:";
    cin>>number;
    cout << "Enter base:";
    cin>> base;
    convertToBase(base,number);

    return a.exec();
}
