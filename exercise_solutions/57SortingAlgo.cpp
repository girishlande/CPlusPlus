// Program to Sort numbers using different sorting algorithms. 

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void printVector(vector<int>& v) {
    cout << "\ndata:";
    for (int a : v) {
        cout << a << " ";
    }
}

void BubbleSort(vector<int>& a) {
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a.size()-1; j++) {
            int current = a[j];
            int next = a[j + 1];
            if (current > next) {
                int temp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = temp;
            }
        }
        printVector(a);
    }
}

void SelectionSort(vector<int>& a) {
    for (int i = 0; i < a.size(); i++) {
        for (int j = i+1; j < a.size(); j++) {
            if (a[i] > a[j]) {
                int temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }
        }
        printVector(a);
    }
}

void SelectionBubbletest() {
    vector<int> a = { 9,4,0,6,1,2,7,8,3 };
    vector<int> b = a;

    cout << "\n\nInput";
    printVector(a);
    cout << "\nBubble sort ";
    BubbleSort(a);

    cout << "\n\nInput";
    printVector(b);
    cout << "\n\nSelection sort";
    SelectionSort(b);
}


void Merge(vector<int>& a, int min, int mid, int max) {
    // create 2 parts of vector min to mid and mid to max
    int fs = min;
    int ss = mid + 1;
    vector<int> b;
    while (fs <= mid && ss <= max) {
        if (a[fs] < a[ss]) {
            b.push_back(a[fs]);
            fs++;
        }
        else {
            b.push_back(a[ss]);
            ss++;
        }
    }

    while (fs <= mid) {
        b.push_back(a[fs]);
        fs++;
    }
    while (ss <= max) {
        b.push_back(a[ss]);
        ss++;
    }

    for (int i = min, bi = 0; i <= max; i++) {
        a[i] = b[bi];
        bi++;
    }
}

void MergeSort(vector<int>& a, int min, int max) {

    if (min >= max) {
        return;
    }

    int mid = (min + max) / 2;
    MergeSort(a, min, mid);
    MergeSort(a, mid + 1, max);
    Merge(a, min, mid, max);
    printVector(a);
}

void MergeSortTest() {
    vector<int> a = { 9,4,0,6,1,2,7,8,3 };
    printVector(a);
    MergeSort(a, 0, a.size() - 1);
    printVector(a);
}

void insertSort(vector<int>& a) {
    for (int i = 1; i < a.size() - 1; i++) {
        int j = i - 1;
        int current = a[i];
        bool flag = false;
        while (j >=0 && current < a[j]) {
            a[j + 1] = a[j];
            j--;
            flag = true;
        }
        if (flag)
            a[j+1] = current;
        printVector(a);
    }
}

void insertionSorttest() {
    vector<int> a = { 9,4,0,6,1,2,7,8,3 };
    printVector(a);
    insertSort(a);
    printVector(a);
}

int main()
{
    insertionSorttest();

}
