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
    void reverseLinkedList(ListNode* prevLeftNode, ListNode* leftNode, ListNode* rightNode) {
        ListNode* currentNode = leftNode;
        ListNode* nextRightNode = rightNode->next;
        ListNode* nextNode = currentNode->next;
        while(currentNode != rightNode) {
            ListNode* nextNextNode = nextNode->next;
            nextNode->next = currentNode;
            currentNode = nextNode;
            nextNode = nextNextNode;
        }
        prevLeftNode->next = rightNode;
        leftNode->next = nextRightNode;
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummyHead = new ListNode(-1, head);
        ListNode* prevLeftNode = nullptr;
        ListNode* leftNode = nullptr;
        ListNode* rightNode = nullptr;

        int position = 1;
        ListNode* prevNode = dummyHead;
        ListNode* currentNode = head;
        while(currentNode != nullptr) {
            if(position == left) {
                leftNode = currentNode;
                prevLeftNode = prevNode;
            }
            if(position == right) {
                rightNode = currentNode;
                break;
            }
            prevNode = currentNode;
            currentNode = currentNode->next;
            position++;
        }

        reverseLinkedList(prevLeftNode, leftNode, rightNode);
        return dummyHead->next;
    }
};
