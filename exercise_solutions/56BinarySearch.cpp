// Program to search a number using binary search algorithm

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool binarySearch(vector<int>& v, int min, int max, int s) {
    if (min == max - 1) {
        if (v[min] == s || v[max] == s)
            return true;
        else
            return false;
    }
    int mid = (min + max) / 2;
    if (v[mid] == s)
        return true;
    else if (v[mid] < s) {
        // search in right half
        min = mid;
    }
    else {
        // search in left half
        max = mid;
    }
    return binarySearch(v, min, max, s);
}

int main()
{
    vector<int> a = { 1,5,7,3,4,8,2 };
    sort(a.begin(),a.end());
    
    cout << "sieof A:" << a.size() << std::endl;

    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }

    cout << "\n Recursive Binary Search result:";
    for (int n = 0; n < 20; n++) {
        cout << "\n" << n << ":" << binarySearch(a, 0, a.size() - 1, n);
    }

    cout << "\n\n Iterating Binary Search result:";
    for (int n = 0; n < 20; n++) {
        int itr = 0;
        int min = 0;
        int max = a.size() - 1;
        bool found = false;
        while (min < max) {
            if (min == max - 1) {
                if (a[min] == n || a[max] == n) {
                    found = true;
                }
                break;
            }
            int mid = (min + max) / 2;
            if (a[mid] == n) {
                found = true;
                break;
            }
            else if (a[mid] < n) {
                min = mid;
            }
            else {
                max = mid;
            }
            itr++;
        }

        if (found) 
            cout << endl << n << " Y.#comparions = " << itr;
        else {
            cout << endl << n << " N.#comparions = " << itr;
        }
    }
}
