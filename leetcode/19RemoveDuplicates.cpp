// ConsoleApplication14.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        int i = 1;
        int j = 1;
        int last = nums[0];
        while (j < nums.size()) {
            if (nums[j] != last) {
                nums[i] = nums[j];
                i++;
                last = nums[j];
            }
            j++;
        }
        return i;
    }
};

ListNode* createNode(int n) {
    ListNode* node = new ListNode(n);
    return node;
}
ListNode* createList(vector<int>& v) {
    ListNode* head = nullptr;
    ListNode* temp = nullptr;
    for (int a : v) {
        if (head == nullptr) {
            head = createNode(a);
            temp = head;
        }
        else {
            ListNode* newnode = createNode(a);
            temp->next = newnode;
            temp = newnode;
        }
    }
    return head;
}

void printList(ListNode* head) {
    ListNode* t = head;
    while (t != nullptr) {
        cout << t->val << " ";
        t = t->next;
    }
    cout << "\n";
}

int main()
{
    vector<int> v1 = { 1,1,1,2,2,3,3 };
    for (auto i : v1)
        cout << i << " ";
    cout << "\n";
    int k = Solution().removeDuplicates(v1);
    for (auto i : v1)
        cout << i << " ";
    cout << "\nK:" << k;
}

