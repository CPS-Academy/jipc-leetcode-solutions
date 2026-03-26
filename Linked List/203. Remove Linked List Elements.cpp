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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return head;
        ListNode* p = head , *prev =NULL ;
        while(p){
            if(p -> val == val) {
                if(prev) {
                    prev -> next = p -> next;
                    p = prev -> next;
                }
                else {
                    head = p -> next;
                    p = head;
                }
            }
            else {
                prev = p;
                p = p -> next;
            }
        }

        return head;
    }
};