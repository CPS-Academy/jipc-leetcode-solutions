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

//USING RECURSIVE APPROACH
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1)return root2;
        if(!root2)return root1;

        root1->val += root2->val;

        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);

        return root1;
    }
};

// USING STACK APPROACH
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1)return root2;
        if(!root2)return root1;

        stack<pair<TreeNode*, TreeNode*>>st;
        st.push({root1, root2});

        while(!st.empty()) {
            auto [node1, node2] = st.top();
            st.pop();

            node1->val += node2->val;

            if(node1->left && node2->left) st.push({node1->left, node2->left});
            else if(!node1->left)node1->left = node2->left;

            if(node1->right && node2->right) st.push({node1->right, node2->right});
            else if(!node1->right)node1->right = node2->right;
        }

        return root1;
    }
};

