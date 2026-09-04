/*
 * LeetCode 129. Sum Root to Leaf Numbers
 *
 * LOGIC:
 * Build the number digit by digit while walking down, instead of collecting the
 * path first and converting it afterwards.
 *
 * 1. `sum` passed into solve() is the number formed by the path ABOVE the
 *    current node. Appending the current digit is `sum = sum * 10 + node->val`
 *    (shift left one decimal place, then add the new digit).
 * 2. At a leaf the number is complete, so return it - that value bubbles up and
 *    gets added into the total.
 * 3. At an internal node return solve(left) + solve(right); the recursion sums
 *    every completed leaf number underneath.
 * 4. A null node contributes 0, which also handles a one-child node correctly
 *    (that side simply adds nothing).
 *
 * The problem guarantees each node value is a single digit 0-9 and the depth is
 * at most 10, so the running number always fits in an int.
 *
 * TIME  : O(n) - each node is visited once.
 * SPACE : O(h) - recursion stack; O(n) for a skewed tree.
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
    int solve(TreeNode *node, int sum)
    {
        if (node == nullptr)
            return 0;

        sum = sum * 10 + node->val;

        if (node->left == nullptr and node->right == nullptr)
            return sum;

        return solve(node->left, sum) + solve(node->right, sum);
    }
    int sumNumbers(TreeNode *root)
    {
        return solve(root, 0);
    }
};