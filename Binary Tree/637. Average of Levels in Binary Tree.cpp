/*
 * LeetCode 637. Average of Levels in Binary Tree
 *
 * LOGIC:
 * Straightforward BFS, but processing one FULL level per outer iteration so the
 * nodes of a level can be averaged together.
 *
 * 1. Push the root and loop while the queue is non-empty.
 * 2. `n = q.size()` is captured BEFORE the inner loop - that snapshot is
 *    exactly the number of nodes on the current level. Children pushed during
 *    the inner loop belong to the next level and are not touched this round.
 *    Reading q.size() inside the loop instead would mix levels together.
 * 3. Pop those n nodes, add their values into `sum`, and enqueue their non-null
 *    children left-to-right.
 * 4. `sum / n` is the average for the level. `sum` is a double, so the division
 *    is floating point (an int sum would truncate, and could also overflow on a
 *    wide level of large values).
 *
 * The problem guarantees at least one node, so the root is never null here.
 *
 * TIME  : O(n) - every node is enqueued and dequeued exactly once.
 * SPACE : O(w) - w = the widest level, up to about n/2 nodes for a full tree.
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
    vector<double> averageOfLevels(TreeNode *root)
    {
        vector<double> ans;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int n = q.size();
            double sum = 0;

            for (int i = 0; i < n; i++)
            {
                TreeNode *node = q.front();
                q.pop();

                sum += node->val;

                if (node->left != nullptr)
                    q.push(node->left);
                if (node->right != nullptr)
                    q.push(node->right);
            }

            ans.push_back(sum / n);
        }
        return ans;
    }
};