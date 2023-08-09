// ConsoleApplication13.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* nthNode = head;
        ListNode* nthNodePrev = nullptr;
        int count = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            temp = temp->next;
            count++;
            if (count > n) {
                nthNodePrev = nthNode;
                nthNode = nthNode->next;
            }
        }

        if (nthNodePrev != nullptr) {
            nthNodePrev->next = nthNode->next;
            delete nthNode;
        }
        else {
            head = nthNode->next;
            delete nthNode;
        }
        
        return head;
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
    Solution s1;
    vector<int> v = { 1,2,3,4,5,6,7,8 };
    ListNode* head = createList(v);
    printList(head);

    ListNode* h = s1.removeNthFromEnd(head, 8);
    printList(h);
}

