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
    TreeNode* convertBST(int st, int end, vector<int>& nums) {
        if(st > end) return nullptr;

        int mid = st + (end - st) / 2;
        TreeNode* root = new TreeNode(nums[mid]);

        root->left = convertBST(st, mid - 1, nums);
        root->right = convertBST(mid + 1, end, nums);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return convertBST(0, nums.size() - 1, nums);
    }
};
