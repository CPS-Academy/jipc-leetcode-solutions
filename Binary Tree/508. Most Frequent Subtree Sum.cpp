/*
 * LeetCode 508. Most Frequent Subtree Sum
 *
 * LOGIC:
 * The subtree sum of a node = its own value + the subtree sums of both
 * children. That is a bottom-up definition, so a POSTORDER traversal computes
 * every subtree sum in a single pass (children finish before the parent needs
 * their results).
 *
 * 1. solve(node) returns the subtree sum rooted at `node`; a null node
 *    contributes 0.
 * 2. Compute `lsum` and `rsum` first, then `sum = lsum + rsum + node->val`.
 * 3. Record it: `mp[sum]++` counts how many subtrees produce that sum, and
 *    `maxF` tracks the highest count seen so far - updating it inside the
 *    traversal avoids a second pass to find the maximum.
 * 4. After the traversal, collect every key whose count equals `maxF`. There
 *    can be ties, which is why the answer is a vector.
 *
 * The map is keyed by the sum (values may be negative, so sums can be negative
 * too - that is fine for a hash map).
 *
 * TIME  : O(n) - one visit per node, O(1) average hash map operations.
 * SPACE : O(n) - up to n distinct sums in the map + O(h) recursion stack.
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
    unordered_map<int, int> mp;
    int maxF = 0;
    int solve(TreeNode *node)
    {
        if (node == nullptr)
            return 0;

        int lsum = solve(node->left);
        int rsum = solve(node->right);

        int sum = lsum + rsum + node->val;

        mp[sum]++;
        maxF = max(maxF, mp[sum]);

        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode *root)
    {
        solve(root);

        vector<int> ans;
        for (auto i : mp)
        {
            if (i.second == maxF)
                ans.push_back(i.first);
        }

        return ans;
    }
};