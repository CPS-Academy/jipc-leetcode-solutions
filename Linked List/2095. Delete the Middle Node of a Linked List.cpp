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
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next == nullptr) {
            return NULL;
        }
        if(head->next->next == nullptr) {
            return new ListNode(head->val);
        }

        auto fastPointer = head;
        auto slowPointer = head;
        int halfLength = 0;
        while(fastPointer != nullptr && fastPointer->next != nullptr) {
            fastPointer = fastPointer->next->next; // jump 2 steps at a time
            slowPointer = slowPointer->next; // jump 1 step at a time
        }
        if(slowPointer->next != nullptr) {
            slowPointer->val = slowPointer->next->val;
            slowPointer->next = slowPointer->next->next;
        }
        else {
            slowPointer->next = nullptr;
        }
        return head;
    }
};
