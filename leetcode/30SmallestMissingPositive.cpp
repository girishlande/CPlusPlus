// ConsoleApplication16.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    /* Utility to swap to integers */
    void swap(int* a, int* b)
    {
        int temp;
        temp = *a;
        *a = *b;
        *b = temp;
    }

    /* Utility function that puts all
    non-positive (0 and negative) numbers on left
    side of arr[] and return count of such numbers */
    int segregate(int arr[], int size)
    {
        int j = 0, i;
        for (i = 0; i < size; i++) {
            if (arr[i] <= 0) {
                swap(&arr[i], &arr[j]);

                // increment count of
                // non-positive integers
                j++;
            }
        }

        return j;
    }

    /* Find the smallest positive missing number
    in an array that contains all positive integers */
    int findMissingPositive(int arr[], int size)
    {
        int i;

        // Mark arr[i] as visited by
        // making arr[arr[i] - 1] negative.
        // Note that 1 is subtracted
        // because index start
        // from 0 and positive numbers start from 1
        cout << "\nBefore negating:";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << "size:" << size << endl;
        for (i = 0; i < size; i++) {
            int index = abs(arr[i]);
            if (index - 1 < size && arr[index - 1] > 0) {
                arr[index - 1] = -arr[index - 1];
                //cout << index << " ";
            }
        }
        cout << "\nAfter negating: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";

        // Return the first index
        // value at which is positive
        for (i = 0; i < size; i++)
            if (arr[i] > 0)

                // 1 is added because
                // indexes start from 0
                return i + 1;

        return size + 1;
    }

    /* Find the smallest positive missing
    number in an array that contains
    both positive and negative integers */
    int findMissing(int arr[], int size)
    {

        // First separate positive
        // and negative numbers
        cout << "\nAfter segregation:";
        int shift = segregate(arr, size);
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        // Shift the array and call
        // findMissingPositive for
        // positive part
        return findMissingPositive(arr + shift,
            size - shift);
    }


    int firstMissingPositive(vector<int>& nums) {
        int* arr = new int[nums.size()];
        int i = 0;
        for (auto a : nums) {
            arr[i] = a;
            i++;
        }
        return findMissing(arr, nums.size());
    }

};

int main()
{
    vector<int> arr = { 99,33,22,11,1,2,3,4,5, };
    cout << "original size :" << arr.size() << endl;
    int missing = Solution().firstMissingPositive(arr);
    cout << "The smallest positive missing number is " << missing;


}

