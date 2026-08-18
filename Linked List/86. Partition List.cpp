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
    ListNode* partition(ListNode* head, int x) {
        ListNode* beforeDummyHead = new ListNode(-1);
        auto beforeCurrentNode = beforeDummyHead;
        ListNode* afterDummyHead = new ListNode(-1);
        auto afterCurrentNode = afterDummyHead;
        while(head != nullptr) {
            if(head->val < x) {
                beforeCurrentNode->next = head;
                beforeCurrentNode = beforeCurrentNode->next;
            }
            else {
                afterCurrentNode->next = head;
                afterCurrentNode = afterCurrentNode->next;
            }
            head = head->next;
        }
        afterCurrentNode->next = nullptr;
        beforeCurrentNode->next = afterDummyHead->next;
        return beforeDummyHead->next;
    }
};
