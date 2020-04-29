#include <QCoreApplication>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>

using namespace std;

// program to count number of set bits in number
int countSetBits(unsigned int n) {

    int count = 0;
    while(n) {
        count+=n&1;
        n= n >> 1;
    }
    return count;
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    cout << countSetBits(15);

    return a.exec();
}
