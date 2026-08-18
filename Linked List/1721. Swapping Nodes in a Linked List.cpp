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
    ListNode* swapNodes(ListNode* head, int k) {
        int listLength = 0;
        ListNode* frontNode = nullptr;
        ListNode* endNode = nullptr;
        ListNode* currentNode = head;
        while(currentNode != nullptr) {
            listLength++;
            if(endNode != nullptr) {
                endNode = endNode -> next;
            }
            if(listLength == k) {
                frontNode = currentNode;
                endNode = head;
            }
            currentNode = currentNode -> next;
        }
        swap(frontNode -> val, endNode -> val);
        return head;
    }
};
