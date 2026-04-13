/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* func(vector<int> &preorder, int &idx, int ub) {
        if(idx == preorder.size() || preorder[idx] > ub)return nullptr;

        TreeNode* node = new TreeNode(preorder[idx]);
        idx++;
        node->left = func(preorder, idx, node->val);
        node->right = func(preorder, idx, ub);

        return node;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx = 0;
        return func(preorder, idx, INT_MAX);
    }
};
