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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr)
            return head;
        ListNode* p1 = head;
        ListNode* p2 = p1->next;
        if (p2 == nullptr)
            return head;
        else
            head = p2;

        ListNode* tail = nullptr;
        while (p1 && p2) {
            if (tail) tail->next = p2;
            ListNode* temp = p2->next;
            p2->next = p1;
            p1->next = temp;
            tail = p1;
            p1 = temp;
            if (p1) {
                p2 = p1->next;
            }
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
    vector<int> v1 = {1,2,3,4,5,6,7};
    vector<int> v2 = { -3,1,4 };
    vector<int> v3 = { -2,-1,0,2 };
    ListNode* head1 = createList(v1);
    ListNode* head2 = createList(v2);
    ListNode* head3 = createList(v3);

    printList(head1);

    ListNode* result = Solution().swapPairs(head1);
    printList(result);
}

