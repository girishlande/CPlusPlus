#include <QCoreApplication>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <fstream>
using namespace std;

// program to count number of occurances of string
int countWordInFile( string word) {
    int count = 0;
    ifstream myReadFile;
    myReadFile.open("D:\\main.cpp");
    string line;
    if (myReadFile.is_open()) {
        while (!myReadFile.eof()) {
            myReadFile >> line;
            if (word.compare(line)==0)
                count++;
        }
    } else {
        cout<<"File not present";
    }
    return count;
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    cout << "count:" << countWordInFile("string");
    return a.exec();
}
