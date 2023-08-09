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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        bool allNUll = true;
        ListNode* head = nullptr;
        for (auto ptr : lists) {
            if (ptr != nullptr) {
                head = ptr;
                allNUll = false;
                break;
            }
        }
        if (allNUll) {
            return nullptr;
        }
        
        ListNode* temphead = head;
        int minVal = head->val;
        int headindex = 0;
        int index = -1;
        for (auto ptr : lists) {
            index++;
            if (!ptr) continue;
            if (ptr->val <= minVal) {
                head = ptr;
                temphead = head;
                headindex = index;
                minVal = ptr->val;
            }
        }
        lists[headindex] = lists[headindex]->next;

        bool allEmpty = false;
        while (!allEmpty) {
            bool minSet = false;
            minVal = 0;
            int headindex = 0;
            bool nodeFound = false;
            allEmpty = true;
            for (int i = 0; i < lists.size(); i++) {
                ListNode* current = lists[i];
                if (current) {
                    allEmpty = false;
                    if (!minSet) {
                        minVal = current->val;
                        minSet = true;
                        headindex = i;
                    }
                    else {
                        if (current->val < minVal) {
                            headindex = i;
                            minVal = current->val;
                        }
                    }
                }
            }

            if (!allEmpty) {
                temphead->next = lists[headindex];
                temphead = lists[headindex];
                ListNode* currentHead = lists[headindex];
                lists[headindex] = currentHead->next;
            }
            
        }
        return head;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if (list1 == nullptr && list2 == nullptr)
            return nullptr;
        if (list1 == nullptr)
            return list2;
        if (list2 == nullptr)
            return list1;
        ListNode * head = list2;
        if (list1->val < list2->val) {
            head = list1;
            list1 = list1->next;
        }
        else {
            list2 = list2->next;
        }
        ListNode* temp = head;

        while (list1 && list2) {
            if (list1->val < list2->val) {
                temp->next = list1;
                temp = list1;
                list1 = list1->next;
            }
            else {
                temp->next = list2;
                temp = list2;
                list2 = list2->next;
            }
        }

        if (list1)
            temp->next = list1;
        if (list2)
            temp->next = list2;
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
    // [[-1,1],[-3,1,4],[-2,-1,0,2]]
    vector<int> v1 = {-1,1};
    vector<int> v2 = { -3,1,4 };
    vector<int> v3 = { -2,-1,0,2 };
    ListNode* head1 = createList(v1);
    ListNode* head2 = createList(v2);
    ListNode* head3 = createList(v3);

    vector<ListNode*> lists;
    lists.push_back(head1);
    lists.push_back(head2);
    lists.push_back(head3);

    for (auto ptr : lists) {
        printList(ptr);
    }

    ListNode* result = Solution().mergeKLists(lists);
    printList(result);
}

