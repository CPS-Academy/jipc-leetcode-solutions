/**
 * Definition for single-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
*/

 class Solution {
    public: 
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* parent = new ListNode(-1);
        ListNode* prev = parent;

        int carry = 0;
        while(l1 || l2 || carry) {
            int digit1 = (l1 != nullptr) ? l1 -> val: 0;
            int digit2 = (l2 != nullptr) ? l2 -> val: 0;

            int sum = digit1 + digit2 + carry;

            prev -> next = new ListNode(sum%10);
            carry = sum/10;

            l1 = l1? l1 -> next: nullptr;
            l2 = l2? l2 -> next: nullptr;
            prev = prev -> next;
        }

        return parent -> next;
    }
 };