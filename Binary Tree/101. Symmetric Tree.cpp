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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q1, q2;
        q1.push(root->left);
        q2.push(root->right);

        while(!q1.empty() && !q2.empty()) {
            TreeNode* a = q1.front();
            TreeNode* b = q2.front();

            q1.pop();
            q2.pop();

            if(!a && !b) continue;
            if(!a || !b) return false;
            if(a->val != b->val) return false;

            q1.push(a->left);
            q2.push(b->right);
            q1.push(a->right);
            q2.push(b->left);
        }

        return q1.empty() && q2.empty();
    }
};
