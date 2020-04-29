#include <iostream>
using namespace std;

// write a function to rotate input array by k elements
// e.g 
// Input : int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
// rotateArray(a, size, 3);
// Output : 7 8 9 1 2 3 4 5 6

// write definition of following function
void rotateArray(int* arr, int size, int k);


void displayArray(int* a, int size)
{
    for (int i = 0; i < size; i++)
        cout << a[i] << "  ";
    cout << endl;
}

int main()
{
    int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int size = sizeof(a) / sizeof(int);
    displayArray(a, size);
    rotateArray(a, size, 3);
    displayArray(a, size);
    return 0;
}

// write definition of following function
void rotateArray(int* arr, int size, int k)
{
    for (int i = 0; i < k; i++) {

        int t = arr[size - 1];
        for (int j = size - 1; j > 0; j--) {
            arr[j] = arr[j - 1];
        }
        arr[0] = t;
    }
}
