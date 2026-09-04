/*
 * LeetCode 1448. Count Good Nodes in Binary Tree
 *
 * LOGIC:
 * A node is "good" when no node on the path from the root to it has a larger
 * value. That only depends on the MAXIMUM seen so far on that path, so a single
 * number can be carried down the recursion instead of the whole path.
 *
 * 1. solve(node, mx) receives `mx` = largest value on the path above (and
 *    including) the current position. The root is seeded with root->val, so the
 *    root always counts itself as good (`>=` is satisfied).
 * 2. Null node -> 0, nothing to count.
 * 3. `node->val >= mx` makes this node good. The comparison is `>=`, not `>`,
 *    because duplicates of the current maximum still count as good.
 * 4. Update `mx = max(mx, node->val)` and pass it to both children. `mx` is a
 *    by-value parameter, so each branch gets its own copy - the left subtree's
 *    maximum never leaks into the right subtree.
 * 5. Return this node's contribution plus both subtree counts.
 *
 * TIME  : O(n) - every node is visited once, O(1) work each.
 * SPACE : O(h) - recursion stack; O(log n) balanced, O(n) skewed.
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
    int goodNodes(TreeNode *root)
    {
        return solve(root, root->val);
    }

    int solve(TreeNode *node, int mx)
    {
        if (node == nullptr)
            return 0;
        int cnt = 0;
        if (node->val >= mx)
            cnt++;

        mx = max(mx, node->val);

        return cnt + solve(node->left, mx) + solve(node->right, mx);
    }
};