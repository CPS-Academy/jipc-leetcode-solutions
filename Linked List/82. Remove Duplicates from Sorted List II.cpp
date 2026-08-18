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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* dummyHead = new ListNode(-1, head);
        auto prevNode = dummyHead;
        auto currentNode = head;
        while(currentNode != nullptr && currentNode->next != nullptr) {
            if(currentNode->val == currentNode->next->val) {
                while(currentNode->next != nullptr && currentNode->val == currentNode->next->val) {
                    currentNode = currentNode->next;
                }
                prevNode->next = currentNode->next;
            }
            else {
                prevNode = prevNode->next;
            }
            currentNode = currentNode->next;
        }

        return dummyHead->next;
    }
};
