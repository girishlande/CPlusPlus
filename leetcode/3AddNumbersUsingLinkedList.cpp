// You are given two non-empty linked lists representing two non-negative integers. 
// The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
// You may assume the two numbers do not contain any leading zero, except the number 0 itsel

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr;
        ListNode* lastNode = nullptr;
        int carry = 0;
        while(l1 && l2) {
            int sum = l1->val + l2->val + carry;
            int rem = sum % 10;
            carry = sum / 10;
            ListNode* curr = new ListNode();
            curr->val = rem;
            curr->next = nullptr;
            if(head==nullptr) head = curr;
            else lastNode->next = curr;
            lastNode = curr;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while(l1) {
            int sum = l1->val + carry;
            int rem = sum % 10;
            carry = sum / 10;
            ListNode* curr = new ListNode();
            curr->val = rem;
            curr->next = nullptr;
            if(head==nullptr) head = curr;
            else lastNode->next = curr;
            lastNode = curr;
            l1 = l1->next;
        }
        
        while(l2) {
            int sum = l2->val + carry;
            int rem = sum % 10;
            carry = sum / 10;
            ListNode* curr = new ListNode();
            curr->val = rem;
            curr->next = nullptr;
            if(head==nullptr) head = curr;
            else lastNode->next = curr;
            lastNode = curr;
            l2 = l2->next;
        }
        
        if (carry) {
            ListNode* curr = new ListNode();
            curr->val = 1;
            curr->next = nullptr;
            if(head==nullptr) head = curr;
            else lastNode->next = curr;
        }
        return head;
        
    }
};