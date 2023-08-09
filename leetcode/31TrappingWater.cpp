// ConsoleApplication16.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findWater(int arr[], int n)
    {
        // left[i] contains height of tallest bar to the
        // left of i'th bar including itself
        int* left = new int[n];

        // Right [i] contains height of tallest bar to
        // the right of ith bar including itself
        int *right = new int[n];

        // Initialize result
        int water = 0;

        // Fill left array
        left[0] = arr[0];
        for (int i = 1; i < n; i++)
            left[i] = max(left[i - 1], arr[i]);

        // Fill right array
        right[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--)
            right[i] = max(right[i + 1], arr[i]);

        // Calculate the accumulated water element by element
        // consider the amount of water on i'th bar, the
        // amount of water accumulated on this particular
        // bar will be equal to min(left[i], right[i]) - arr[i]
        // .
        for (int i = 1; i < n - 1; i++) {
            int var = min(left[i - 1], right[i + 1]);
            if (var > arr[i]) {
                water += var - arr[i];
            }
        }

        return water;
    }

    int trap(vector<int>& arr) {
        int* data = new int[arr.size()];
        int i = 0;
        for (int a : arr) {
            data[i] = a;
            i++;
        }
        return findWater(data, i);
    }   

};

int main()
{
    vector<int> heights{ 0,1,0,2,1,0,1,3,2,1,2,1 };
    cout << Solution().trap(heights);

}

