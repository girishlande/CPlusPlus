#include <QCoreApplication>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

// write a program to find 2 numbers whose sum is "sum"
void findSumPair(vector<int> a, int sum) {

    for(int i=0;i<a.size();i++) {
        for (int j=i+1;j<a.size();j++) {
            if (a[i]+a[j]==sum) {
                cout << a[i] << "  " << a[j];
            }
        }
    }
}

void findSumPair2(vector<int> a, int sum) {
    sort(a.begin(),a.end());
    int front = 0;
    int rear = a.size()-1;
    while(front<rear) {
        if (a[front]+a[rear]==sum) {
            cout << a[front] << "  " << a[rear];
            front++;
        } else if (a[front]+a[rear]<sum) {
            front++;
        } else{
            rear--;
        }
    }

}

void findSumPair3(vector<int> a, int sum) {
    set<int> items;
    for(auto i:a) {
        int item = sum-i;
        if (items.find(item)!=items.end()) {
            cout << i << "  " << item;
        }
        items.insert(i);

    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    vector<int> items = {10,20,5,30,7,40,2};
    findSumPair2(items,42);


    return a.exec();
}
