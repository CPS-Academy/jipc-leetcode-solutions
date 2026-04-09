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
    TreeNode* helper(vector<int>&preorder, vector<int>&inorder, int &index, int left, int right) {
        if(left > right)return nullptr;

        TreeNode* root = new TreeNode(preorder[index]);
        int inIndex;
        for(int i = left; i <= right; i++)
        {
            if(preorder[index] == inorder[i])
            {
                inIndex = i;
                break;
            }
        }

        index++;

        root->left = helper(preorder, inorder, index, left, inIndex-1);
        root->right = helper(preorder, inorder, index, inIndex+1, right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;
        return helper(preorder, inorder, index, 0, preorder.size()-1);
    }
};
