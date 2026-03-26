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
    void reorderList(ListNode* head) {
        if(head == NULL) {
            return;
        }
        //middle of the linked list
        ListNode *slow = head, *fast = head;
        while(fast && fast -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        //Reverse linked list
        ListNode *prev = NULL, *cur = slow, *temp;
        while(cur) {
            temp = cur -> next;
            cur -> next = prev;
            prev = cur;
            cur = temp;
        }

        //Merge Two Linked list
        ListNode *firstHead = head, *secondHead = prev;
        while(secondHead -> next) {
            temp = firstHead -> next;
            firstHead -> next = secondHead;
            firstHead = temp;

            temp = secondHead -> next;
            secondHead -> next = firstHead;
            secondHead = temp;
        }
    }
};