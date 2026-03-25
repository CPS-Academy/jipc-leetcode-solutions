/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* detectCycle(ListNode *head) {
        if(head == nullptr) return nullptr;
        ListNode *fast = head, *slow = head;
        do {
            slow = slow -> next;
            if(fast -> next == nullptr) return nullptr;
            fast = fast -> next -> next;
        } while(fast != nullptr && fast != slow);


        if(fast == nullptr) return nullptr;
        //if(fast == slow)
        slow = head;
        while(fast != slow){
            fast = fast -> next;
            slow = slow -> next;
        }
        return fast;
    }
};
