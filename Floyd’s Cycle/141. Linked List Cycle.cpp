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
    bool hasCycle(ListNode *head) {
        if(head == nullptr) return false;
        ListNode *fast = head, *slow = head;
        do {
            slow = slow -> next;
            if(fast -> next == nullptr) return false;
            fast = fast -> next -> next;
        } while(fast != nullptr && fast != slow);


        if(fast == nullptr) return false;
        //if(fast == slow)
        return true;
    }
};
