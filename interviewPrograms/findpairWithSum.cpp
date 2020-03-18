#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

// write a program to find 2 numbers whose sum is "sum"
// void main() {
//   vector<int> items = { 0, 10, 20, 5, 30, 7, 40, 25 };
//   findSumPair3(items, 30);
// }
// output:
// 20 10 
// 30 0 
// 25 5

// method 1 : Brute force. Take each number and check with all remaining numbers
// time complexity: O(n^2)
void findSumPair(vector<int> a, int sum)
{
    for (int i = 0; i < a.size(); i++) {
        for (int j = i + 1; j < a.size(); j++) {
            if (a[i] + a[j] == sum) {
                cout << a[i] << "  " << a[j] << endl;
            }
        }
    }
}

// method 2 : sort and then linear using 2 pointers front and rear
// time complexity : O(nlogn) + o(n)
void findSumPair2(vector<int> a, int sum)
{
    sort(a.begin(), a.end());
    int front = 0;
    size_t rear = a.size() - 1;
    while (front < rear) {
        if (a[front] + a[rear] == sum) {
            cout << a[front] << "  " << a[rear] << endl;
            front++;
        } else if (a[front] + a[rear] < sum) {
            front++;
        } else {
            rear--;
        }
    }
}

// method 3 : iterate on all items and check if sum-item is present in set.
// time complexity: O(n) + search complexity of set
void findSumPair3(vector<int> a, int sum)
{
    set<int> items;
    for (auto i : a) {
        int item = sum - i;
        if (items.find(item) != items.end()) {
            cout << i << "  " << item << endl;
        }
        items.insert(i);
    }
}

int main(int argc, char* argv[])
{
    vector<int> items = { 0, 10, 20, 5, 30, 7, 40, 25 };
    findSumPair3(items, 30);

    return 0;
}
