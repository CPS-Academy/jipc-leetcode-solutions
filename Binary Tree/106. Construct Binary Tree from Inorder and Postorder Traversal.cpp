/*
 * LeetCode 106. Construct Binary Tree from Inorder and Postorder Traversal
 *
 * LOGIC:
 * In postorder the LAST element is always the root of the current range, and
 * in inorder the root splits the range into [left subtree | root | right subtree].
 *
 * 1. Store value -> index of inorder in the hash map `pos` so the split point
 *    can be found in O(1) instead of scanning the array every time.
 * 2. Keep a global pointer `idx` starting at n-1 and walk postorder BACKWARDS.
 *    Every call consumes one value from the back, that value is the root.
 * 3. `mid = pos[val]` splits the inorder range: [left, mid-1] is the left
 *    subtree and [mid+1, right] is the right subtree.
 * 4. Because postorder is being read in reverse (root -> right -> left), the
 *    RIGHT child must be built BEFORE the left child. Swapping these two lines
 *    breaks the answer.
 * 5. `left > right` means an empty range -> return nullptr.
 *
 * TIME  : O(n) - each node is created once, the split index is an O(1) lookup.
 * SPACE : O(n) - hash map of n entries + recursion stack up to O(h),
 *                where h = n in the worst case (skewed tree).
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
    unordered_map<int, int> pos;
    int idx;
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int n = inorder.size();
        for (int i = 0; i < n; i++)
            pos[inorder[i]] = i;
        idx = n - 1;
        return build(inorder, postorder, 0, n - 1);
    }

    TreeNode *build(vector<int> &inorder, vector<int> &postorder, int left, int right)
    {
        if (left > right)
            return nullptr;

        int val = postorder[idx];
        idx--;

        TreeNode *root = new TreeNode(val);

        int mid = pos[val];

        root->right = build(inorder, postorder, mid + 1, right);
        root->left = build(inorder, postorder, left, mid - 1);

        return root;
    }
};