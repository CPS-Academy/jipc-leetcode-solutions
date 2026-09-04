/*
 * LeetCode 173. Binary Search Tree Iterator
 *
 * LOGIC:
 * An inorder traversal of a BST visits values in sorted order. Instead of
 * flattening the whole tree into an array up front (O(n) memory), this pauses
 * the traversal by keeping the recursion stack manually.
 *
 * 1. `pushLeft(node)` walks as far left as possible, pushing every node on the
 *    way. The stack top is therefore always the smallest value not yet returned.
 * 2. The constructor calls pushLeft(root), which seeds the stack with the left
 *    spine of the tree.
 * 3. next(): pop the top (the next smallest). Before returning it, its right
 *    subtree becomes the new "smallest unvisited" region, so pushLeft(top->right)
 *    pushes that subtree's left spine.
 * 4. hasNext(): the stack is non-empty exactly while nodes remain.
 *
 * TIME  : next() is O(h) worst case but O(1) AMORTIZED - each node is pushed
 *         and popped at most once across all n calls, so n calls cost O(n)
 *         total. hasNext() is O(1). Constructor is O(h).
 * SPACE : O(h) - the stack never holds more than one root-to-leaf path;
 *         O(log n) if balanced, O(n) if skewed.
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
class BSTIterator
{
public:
    stack<TreeNode *> st;

    void pushLeft(TreeNode *node)
    {
        while (node != nullptr)
        {
            st.push(node);
            node = node->left;
        }
    }
    BSTIterator(TreeNode *root)
    {
        pushLeft(root);
    }
    bool hasNext()
    {
        return !st.empty();
    }
    int next()
    {
        TreeNode *top = st.top();
        st.pop();
        if (top->right != nullptr)
        {
            pushLeft(top->right);
        }
        return top->val;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */