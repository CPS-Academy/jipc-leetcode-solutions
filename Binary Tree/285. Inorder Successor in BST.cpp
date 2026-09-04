/*
 * LeetCode 285. Inorder Successor in BST
 *
 * LOGIC:
 * The inorder successor is the smallest value in the tree that is strictly
 * greater than p->val. Using the BST ordering this can be found in one downward
 * pass, with no parent pointers and no full traversal.
 *
 * 1. Start at the root with `ans = nullptr`.
 * 2. If `root->val > p->val`, this node is a valid candidate (it is greater
 *    than p), so record it in `ans` - but a smaller valid answer might still
 *    exist on the left, so move left. Each later candidate overwrites the
 *    previous one, which keeps the SMALLEST value greater than p.
 * 3. If `root->val <= p->val`, this node and its whole left subtree are too
 *    small, so move right without touching `ans`.
 * 4. When the walk falls off the tree, `ans` holds the successor, or nullptr
 *    if p is the maximum node.
 *
 * This also covers the case where p has no right subtree - the answer is then
 * the last ancestor from which we turned left, which is exactly what step 2
 * records.
 *
 * TIME  : O(h) - a single root-to-leaf descent; O(log n) balanced, O(n) skewed.
 * SPACE : O(1) - iterative, only the `ans` pointer is kept.
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p)
    {
        TreeNode *ans = nullptr;

        while (root != nullptr)
        {
            if (root->val > p->val)
            {
                ans = root;
                root = root->left;
            }
            else
                root = root->right;
        }

        return ans;
    }
};