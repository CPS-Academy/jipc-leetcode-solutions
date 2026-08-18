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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummyHead(0);
        dummyHead.next = head;
        ListNode* groupPrevNode = &dummyHead;
        while(true) {
            ListNode* kthNode = groupPrevNode;
            for(int i = 0; i < k; i++) {
                kthNode = kthNode->next;
                if(kthNode == nullptr) {
                    return dummyHead.next;
                }
            }

            ListNode* groupNext = kthNode->next;
            ListNode* prevNode = groupNext;
            ListNode* currentNode = groupPrevNode->next;
            while(currentNode != groupNext) {
                ListNode* nextNode = currentNode->next;
                currentNode->next = prevNode;
                prevNode = currentNode;
                currentNode = nextNode;
            }

            ListNode* oldGroupStart = groupPrevNode->next;
            groupPrevNode->next = kthNode;
            groupPrevNode = oldGroupStart;
        }
    }
};
