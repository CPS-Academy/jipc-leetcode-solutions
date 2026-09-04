/*
 * LeetCode 112. Path Sum
 *
 * LOGIC:
 * Instead of adding values up the tree, subtract the current node's value from
 * the target on the way down, so each call only has to answer:
 * "can the subtree below me produce exactly `targetSum`?"
 *
 * 1. Empty node -> false. An empty tree has no root-to-leaf path at all.
 * 2. Leaf node (no left and no right) -> the path ends here, so the answer is
 *    true only if `root->val == targetSum` (the remaining amount is exactly
 *    consumed by this last node).
 * 3. Otherwise recurse into both children with `targetSum - root->val`.
 *    `||` short-circuits, so the right subtree is skipped once the left one
 *    already found a valid path.
 *
 * NOTE: node values can be negative, so a partial sum going above the target
 * is NOT a reason to prune - every path must be walked to its leaf.
 *
 * TIME  : O(n) - worst case every node is visited once.
 * SPACE : O(h) - recursion stack; O(log n) if balanced, O(n) if skewed.
 */

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
class Solution
{
public:
    int sum = 0;
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (root == nullptr)
            return false;

        if (root->left == nullptr && root->right == nullptr)
            return root->val == targetSum;

        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    }
};