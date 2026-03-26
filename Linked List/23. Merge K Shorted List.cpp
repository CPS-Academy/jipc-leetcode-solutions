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
    ListNode* merge(ListNode* l1, ListNode* l2 ) {
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;
        if(l1->val < l2->val) {
            l1->next = merge(l1->next, l2);
            return l1;
        } else {
            l2->next = merge(l1, l2->next);
            return l2;
        }
    }

    //helper divides and merge two halved lists
    ListNode* mergeKListsHelper(vector<ListNode*>& lists, int l, int r) {
        if(l > r) return nullptr;
        if(l == r) return lists[l];
        int m = l + (r - l) / 2;
        ListNode *h1 = mergeKListsHelper(lists, l, m),
                 *h2 = mergeKListsHelper(lists, m + 1, r);
        return merge(h1, h2);
    }

    //Divide and conquer method
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeKListsHelper(lists, 0, (int)lists.size() - 1);
    }
};

/*
TC : O(nlogk) wherer k is the size of the list n is the total number of node
SC: O(n)
*/