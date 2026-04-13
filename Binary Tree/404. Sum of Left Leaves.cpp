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
    void recur(TreeNode* node, string origin, int &sum) {
        if(!node->left && !node->right && origin=="L")sum += node->val;
        if(node->left)recur(node->left, "L", sum);
        if(node->right)recur(node->right, "R", sum);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        string origin = "";
        recur(root, origin, sum);
        return sum;
    }
};
