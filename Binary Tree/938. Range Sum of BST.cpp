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

//Approach 1 - Without BST optimization (checks both sides always):
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        if(!root)return sum;

        if(root->val >= low && root->val <= high)sum += root->val;
        sum += rangeSumBST(root->left, low, high);
        sum += rangeSumBST(root->right, low, high);

        return sum;
    }
};

//Approach 2 - With BST optimization (prunes unnecessary branches):
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        if(!root)return sum;

        if(root->val >= low && root->val <= high)sum += root->val;
        if(root->val > low)sum += rangeSumBST(root->left, low, high);
        if(root->val < high)sum += rangeSumBST(root->right, low, high);

        return sum;
    }
};
