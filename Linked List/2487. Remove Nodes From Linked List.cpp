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
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prevNode = nullptr;
        ListNode* currentNode = head;
        while(currentNode != nullptr) {
            ListNode* nextNode = currentNode->next;
            currentNode->next = prevNode;
            prevNode = currentNode;
            currentNode = nextNode;
        }
        return prevNode;
    }
public:
    ListNode* removeNodes(ListNode* head) {
        head = reverseList(head);
        
        int maxValue = 0;
        ListNode* prevNode = nullptr;
        ListNode* currentNode = head;
        while(currentNode != nullptr) {
            maxValue = max(maxValue, currentNode->val);
            if(currentNode->val < maxValue) {
                prevNode->next = currentNode->next;
                ListNode* deleted = currentNode;
                currentNode = currentNode->next;
                // deleted->next = nullptr;
                delete deleted;
            }
            else{
                prevNode = currentNode;
                currentNode = currentNode->next;
            }
        }
        return reverseList(head);
    }
};
