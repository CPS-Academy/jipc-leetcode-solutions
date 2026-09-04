/*
 * LeetCode 863. All Nodes Distance K in Binary Tree
 *
 * LOGIC:
 * Distance here spreads in ALL directions - down into the subtree, but also up
 * through the parent and back down the other side. A binary tree only stores
 * downward links, so the first step is to turn it into an undirected graph.
 *
 * 1. buildParent() does a DFS recording `mp[node] = parent`. Now every node has
 *    three neighbours: left, right and parent. The root maps to nullptr.
 * 2. BFS outward from `target`, because BFS expands strictly by distance - all
 *    nodes at distance d are dequeued before any node at distance d+1.
 * 3. `vis` prevents walking back the way we came (e.g. down to a child and
 *    immediately back up to the same parent), which would loop forever.
 * 4. `dis` counts completed levels. When `dis == k`, everything currently in
 *    the queue is exactly k edges from target - drain it into the answer and
 *    return.
 * 5. If the queue empties before dis reaches k, no node is that far away, so
 *    return an empty vector.
 *
 * The nullptr check on `mp[node]` also stops the root from pushing a fake
 * parent into the queue.
 *
 * TIME  : O(n) - one DFS to map parents + one BFS touching each node once.
 * SPACE : O(n) - parent map + visited set + queue.
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
    unordered_map<TreeNode *, TreeNode *> mp;
    void buildParent(TreeNode *node, TreeNode *parent)
    {
        if (node == nullptr)
            return;

        mp[node] = parent;
        buildParent(node->left, node);
        buildParent(node->right, node);
    }
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        buildParent(root, nullptr);

        queue<TreeNode *> q;
        unordered_set<TreeNode *> vis;

        q.push(target);
        vis.insert(target);

        int dis = 0;

        while (!q.empty())
        {
            int n = q.size();

            if (dis == k)
            {
                vector<int> ans;
                for (int i = 0; i < n; i++)
                {
                    ans.push_back(q.front()->val);
                    q.pop();
                }

                return ans;
            }

            for (int i = 0; i < n; i++)
            {
                TreeNode *node = q.front();
                q.pop();

                if (node->left != nullptr and !vis.count(node->left))
                {
                    q.push(node->left);
                    vis.insert(node->left);
                }
                if (node->right != nullptr and !vis.count(node->right))
                {
                    q.push(node->right);
                    vis.insert(node->right);
                }
                if (mp[node] and !vis.count(mp[node]))
                {
                    q.push(mp[node]);
                    vis.insert(mp[node]);
                }
            }
            dis++;
        }

        return {};
    }
};