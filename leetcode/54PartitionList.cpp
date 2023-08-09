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
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr)
            return head;

        ListNode * s = nullptr;
        ListNode * h1 = head;
        ListNode * h2 = head->next;
        if (h2 == nullptr)
            return head;

        ListNode * newhead = h1;
        ListNode * h1prev = nullptr;
        // Find first larger number than x
        while (h1->val < x) {
            h1prev = h1;
            h1 = h1->next;
            if (h1 == nullptr)
                return newhead;
        }
        h2 = h1->next;
        ListNode* h2prev = h1;
        while (h2) {
            if (h2->val >= x) {
                h2prev = h2;
                h2 = h2->next;
                continue;
            }
            if (h2->val < h1->val) {
                ListNode* h2Next = h2->next;
                h2prev->next = h2Next;
                if (h1prev) {
                    h1prev->next = h2;
                    h2->next = h1;
                    h1prev = h2;
                }
                else {
                    h1prev = h2;
                    newhead = h2;
                    h2->next = h1;
                }
                h2 = h2prev->next;
            }
            else {
                h2prev = h2;
                h2 = h2->next;
            }

        }
        return newhead;
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
    //vector<int> v = { 1,4,3,2,5,2 };
    //vector<int> v = { 1,1,1,2,3 };
    //vector<int> v = { 1,1 };
    //vector<int> v = { 1,2,2 };
     //vector<int> v = { 1,1,2 };
    //vector<int> v = { 2,1 };
    vector<int> v = { 1,4,3,0,5,2 };
    ListNode* h = createList(v);
    cout << "\ninput:";
    printList(h);

    ListNode* h1 = Solution().partition(h, 2);
    cout << "\n Output:";
    printList(h1);

}

