// ConsoleApplication18.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
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
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums;
        int i = 0;
        int j = 0;
        while(i<m && j<n) {
            if (nums1[i] < nums2[j]) {
                nums.push_back(nums1[i++]);
            }
            else {
                nums.push_back(nums2[j++]);
            }
        }
        while (i < m) {
            nums.push_back(nums1[i++]);
        }
        while (j < n) {
            nums.push_back(nums2[j++]);
        }
        for (size_t i = 0; i < nums.size(); i++) {
            nums1[i] = nums[i];
        }
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
    vector<int> nums1 = { 1, 2, 3, 0, 0, 0 };
    vector<int> nums = { 2, 5, 6 };
    int m = 3;
    int n = 3;
    Solution().merge(nums1, 3, nums, 3);
    for (auto a : nums1) {
        cout << a << " ";
    }

}

