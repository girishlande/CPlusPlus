#include <QCoreApplication>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

// write a program to calculate century from year
//Given a year, return the century it is in. The first century spans from
//the year 1 up to and including the year 100, the second - from the year 101 up
//to and including the year 200, etc.

// Example
//* For `year = 1905`, the output should be centuryFromYear(year) = 20
//* For `year = 1700`, the output should be centuryFromYear(year) = 17

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int year;
    cout <<"Enter year:";
    cin>>year;
    int r = year/100;
    bool cstart = year%100==0;
    if (!cstart) {
        r=r+1;
    }
    cout << "Century is:" <<r;
    return a.exec();
}
