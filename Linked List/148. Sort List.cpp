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
    ListNode* merge(ListNode* leftSubList, ListNode* rightSubList) {
        ListNode* dummyNode = new ListNode(0);
        auto currentNode = dummyNode;
        while(leftSubList != nullptr && rightSubList != nullptr) {
            if(leftSubList->val < rightSubList->val) {
                currentNode->next = leftSubList;
                leftSubList = leftSubList->next;
            }
            else {
                currentNode->next = rightSubList;
                rightSubList = rightSubList->next;
            }
            currentNode = currentNode->next;
        }

        if(leftSubList != nullptr) {
            currentNode->next = leftSubList;
        }
        if(rightSubList != nullptr) {
            currentNode->next = rightSubList;
        }

        return dummyNode->next;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }
        auto fastPointer = head;
        auto slowPointer = head;
        auto prevPointer = head;
        while(fastPointer != nullptr && fastPointer->next != nullptr) {
            prevPointer = slowPointer;
            fastPointer = fastPointer->next->next;
            slowPointer = slowPointer->next;
        }
        prevPointer->next = nullptr;
        
        ListNode* leftSubList = sortList(head);
        ListNode* rightSubList = sortList(slowPointer);

        return merge(leftSubList, rightSubList);
    }
};
