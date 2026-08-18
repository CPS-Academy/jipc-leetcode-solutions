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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr) {
            return NULL;
        }

        auto tailNode = head;
        int listSize = 1;
        while(tailNode -> next != nullptr) {
            tailNode = tailNode -> next;
            listSize++;
        }

        // cout << "tail Node Value: " << tailNode -> val << '\n';
        // cout << "head Node Value: " << head -> val << '\n';

        tailNode -> next = head;
        k %= listSize;
        int rem = listSize - k;

        auto currentNode = head;
        ListNode* newTailNode = nullptr;
        while(rem--) {
            newTailNode = currentNode;
            currentNode = currentNode -> next;
        }
        newTailNode -> next = nullptr;

        return currentNode;
    }
};
