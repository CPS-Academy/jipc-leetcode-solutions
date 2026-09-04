/*
 * LeetCode 572. Subtree of Another Tree
 *
 * LOGIC:
 * `subRoot` is a subtree of `root` if SOME node of root starts a region that is
 * structurally identical to subRoot. So the problem reduces to running the
 * "Same Tree" check (LeetCode 100) at every node of root.
 *
 * isSameTree(p, q) - exact match check:
 * 1. Both null -> true (two empty trees match).
 * 2. Exactly one null -> false (shapes differ).
 * 3. Values differ -> false.
 * 4. Otherwise both left and right sides must match too (&&).
 *
 * isSubtree(root, subRoot):
 * 1. Ran out of root without a match -> false.
 * 2. Try an exact match starting at the current node; if it matches, done.
 * 3. Otherwise ask the same question of the left subtree, then the right.
 *    `||` short-circuits as soon as one side succeeds.
 *
 * IMPORTANT: the check must be a FULL match, not "subRoot's values appear
 * somewhere below". Matching a node's value is not enough - the whole shape
 * below it has to line up, which is what step 4 of isSameTree enforces.
 *
 * TIME  : O(n * m) - n nodes of root, each running a comparison that costs up
 *                    to m, the size of subRoot.
 * SPACE : O(n) - recursion stack, bounded by the height of root (O(n) skewed).
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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == nullptr and q == nullptr)
            return true;
        if (p == nullptr or q == nullptr)
            return false;
        if (p->val != q->val)
            return false;

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if (root == nullptr)
            return false;

        if (isSameTree(root, subRoot))
            return true;

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};