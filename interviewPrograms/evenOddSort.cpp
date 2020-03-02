#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void sortEvenOdd(int a[], int len,int *output)
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
            if (oddcounter< len && a[oddcounter] % 2 == 1)
                output[index++] = a[oddcounter++];
        } else {
            if (oddcounter < len && a[oddcounter] % 2 == 1)
                output[index++] = a[oddcounter++];
            if (evencounter < len && a[evencounter] % 2 == 0)
                output[index++] = a[evencounter++];
        }

    }
}

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
    int input[] = { 11, 18, 29, 7, 4, 8, 19, 1, 3, 6, 2, 10, 55, 33, 13, 15 };
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
