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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr)
            return head;

        ListNode* h1 = head;
        ListNode* h2 = head->next;
        if (h2 == nullptr)
            return h1;
        ListNode* newhead = nullptr;
        ListNode* prev = nullptr;
        while (1) {

            if (h1->val == h2->val) {
                while (h1->val == h2->val) {
                    delete h1;
                    h1 = h2;
                    h2 = h2->next;
                    if (h2 == nullptr) {
                        delete h1;
                        if (prev) {
                            prev->next = nullptr;
                        }
                        return newhead;
                    }
                }
                delete h1;
                h1 = h2;
                h2 = h2->next;
                if (h2 == nullptr) {
                    if (prev) {
                        prev->next = h1;
                    }
                    else {
                        newhead = h1;
                    }
                    return newhead;
                }
            }
            else {
                if (prev) {
                    prev->next = h1;
                    prev = h1;
                }
                if (newhead == nullptr) {
                    newhead = h1;
                    prev = h1;
                } 
                h1 = h2;
                h2 = h2->next;
                if (h2 == nullptr) {
                    return newhead;
                }
            }
            
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
     // vector<int> v = { 1,2,3,3,4,4,5 };
    //vector<int> v = { 1,1,1,2,3 };
    //vector<int> v = { 1,1 };
    //vector<int> v = { 1,2,2 };
    vector<int> v = { 1,1,2 };

    ListNode* h = createList(v);
    cout << "\ninput:";
    printList(h);

    ListNode* h1 = Solution().deleteDuplicates(h);
    cout << "\n Output:";
    printList(h1);

}

