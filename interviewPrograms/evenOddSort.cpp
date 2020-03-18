#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// Write a program to sort array such that 
// numbers at alternate positions are all even or odd
// e.g output
// original array : 11, 12, 4, 8, 19, 1, 3, 6, 10, 13, 15,
//    sorted array : 1, 3, 4, 6, 8, 10, 11, 12, 13, 15, 19,
//    Even odd sorted array : 1, 4, 3, 6, 11, 8, 13, 10, 15, 12, 19,
// Write definition of following function 
// void sortEvenOdd(int a[], int len, int* output)

void sortEvenOdd(int a[], int len, int* output);

void sortArray(int a[], int len)
{
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (a[i] > a[j]) {
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
}

void displayArray(int a[], int len)
{
    for (int i = 0; i < len; i++) {
        cout << a[i] << ", ";
    }
    cout << endl;
}

int main()
{
    int input[] = { 11, 12, 4, 8, 19, 1, 3, 6, 10, 13, 15 };
    int len = sizeof(input) / sizeof(int);
    cout << "original array:" << endl;
    displayArray(input, len);
    cout << "sorted array:" << endl;
    sortArray(input, len);
    displayArray(input, len);

    cout << "Even odd sorted array:" << endl;
    int* output = new int[len];
    sortEvenOdd(input, len, output);
    displayArray(output, len);

    return 0;
}

void sortEvenOdd(int a[], int len, int* output)
{
    int index = 0;
    int evencounter = 0;
    int oddcounter = 0;
    bool even = a[0] % 2 == 0;
    while (evencounter < len || oddcounter < len) {
        while (evencounter < len) {
            if (a[evencounter] % 2 == 0)
                break;
            evencounter++;
        }
        while (oddcounter < len) {
            if (a[oddcounter] % 2 == 1)
                break;
            oddcounter++;
        }
        if (even) {
            if (evencounter < len && a[evencounter] % 2 == 0)
                output[index++] = a[evencounter++];
            if (oddcounter < len && a[oddcounter] % 2 == 1)
                output[index++] = a[oddcounter++];
        } else {
            if (oddcounter < len && a[oddcounter] % 2 == 1)
                output[index++] = a[oddcounter++];
            if (evencounter < len && a[evencounter] % 2 == 0)
                output[index++] = a[evencounter++];
        }
    }
}
