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
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;

        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;

        while(!q.empty()) {
            int level_size = q.size();
            depth++;
            for(int i = 0; i < level_size; i++) {
                TreeNode* tmp_node = q.front();
                q.pop();

                if(tmp_node->left != nullptr) q.push(tmp_node->left);
                if(tmp_node->right != nullptr) q.push(tmp_node->right);
            }
        }

        return depth;
    }
};
