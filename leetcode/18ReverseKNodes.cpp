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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr) return head;

        ListNode* nextGroup = head;
        ListNode* result = nullptr;
        ListNode* tail = nullptr;
        while (nextGroup) {
            ListNode* temp = nextGroup;

            // Push group of 'k' elements on stack
            stack<ListNode*> st;
            int count = k;
            while (temp != nullptr && count != 0) {
                st.push(temp);
                temp = temp->next;
                count--;
            }
            if (count == 0) {
                // this means we have group of 'k' nodes
                ListNode* p1 = st.top();
                if (result == nullptr)
                    result = p1;
                if (tail)
                    tail->next = p1;
                nextGroup = p1->next;
                st.pop();

                while (!st.empty()) {
                    ListNode* p2 = st.top();
                    st.pop();
                    p1->next = p2;
                    p1 = p2;
                }
                tail = p1;
                p1->next = nextGroup;
            }
            else {
                nextGroup = nullptr;
            }
        }

        return result;
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
    vector<int> v1 = {1,2,3,4,5,6,7,8,9};
    vector<int> v2 = { -3,1,4 };
    vector<int> v3 = { -2,-1,0,2 };
    ListNode* head1 = createList(v1);
    ListNode* head2 = createList(v2);
    ListNode* head3 = createList(v3);

    printList(head1);

    ListNode* result = Solution().reverseKGroup(head1,2);
    printList(result);
}

