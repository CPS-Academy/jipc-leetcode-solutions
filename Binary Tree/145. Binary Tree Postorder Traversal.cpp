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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        stack<TreeNode*> st;
        TreeNode* curr = root;

        while(curr or !st.empty()) {
            if(curr) {
                v.push_back(curr->val);
                st.push(curr);
                curr = curr->right;
            }
            else {
                curr = st.top();
                st.pop();
                curr = curr->left;
            }
        }

        reverse(v.begin(), v.end());

        return v;
    }
};
