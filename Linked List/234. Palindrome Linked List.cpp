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
    ListNode* endOfFirstHalf(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    ListNode* reverseList(ListNode* node) {
        ListNode* prevNode = nullptr;
        auto currentNode = node;
        while(currentNode != nullptr) {
            ListNode* nextNode = currentNode->next;
            currentNode->next = prevNode;
            prevNode = currentNode;
            currentNode = nextNode;
        }
        return prevNode;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head -> next == nullptr) {
            return true;
        }
        ListNode* firstHalfEnd = endOfFirstHalf(head);
        // cout << firstHalfEnd->val << '\n';
        ListNode* secondHalfStart = reverseList(firstHalfEnd->next);

        ListNode* firstPointer = head;
        ListNode* lastPointer = secondHalfStart;
        while(lastPointer != nullptr) {
            if(firstPointer->val != lastPointer->val) {
                return false;
            }
            firstPointer = firstPointer->next;
            lastPointer = lastPointer->next;
        }
        return true;
    }
};
