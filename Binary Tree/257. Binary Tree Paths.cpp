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
    void helper(TreeNode* node, string s, vector<string> &ans) {
        if(node->left == nullptr and node->right == nullptr)
            ans.push_back(s);

        if(node->left)
        {
            helper(node->left, s + "->" + to_string(node->left->val), ans);
        }

        if(node->right)
        {
            helper(node->right, s + "->"+ to_string(node->right->val), ans);
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string s = to_string(root->val);
        helper(root, s, ans);
        return ans;
    }
};
