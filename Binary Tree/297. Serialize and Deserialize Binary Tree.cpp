/*
 * LeetCode 297. Serialize and Deserialize Binary Tree
 *
 * LOGIC:
 * A level-order (BFS) encoding where every missing child is written as "#".
 * Recording the nulls is what makes the string unambiguous - without them the
 * same sequence could rebuild into several different shapes.
 *
 * serialize:
 * 1. Empty tree is the special case "#".
 * 2. BFS with a queue, but BOTH children are pushed even when they are null.
 * 3. When a popped node is null, append "# " and continue; otherwise append its
 *    value and push its two children. The result is a space-separated level
 *    order listing with explicit null markers.
 *
 * deserialize:
 * 1. "#" rebuilds the empty tree.
 * 2. Read the first token as the root, push it into a queue.
 * 3. For each popped node read exactly TWO tokens - its left child then its
 *    right child. A real number becomes a new node that gets queued (its own
 *    children come later in the stream); a "#" is skipped, leaving the pointer
 *    null.
 * 4. The queue order in deserialize mirrors the queue order in serialize, so
 *    the tokens always line up with the correct parent.
 *
 * TIME  : O(n) for both directions - one visit per node/marker.
 * SPACE : O(n) - the queue holds up to one full level, plus the output string.
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
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (root == nullptr)
            return "#";

        string s;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();

            if (node == nullptr)
            {
                s += "# ";
                continue;
            }

            s += to_string(node->val) + " ";

            q.push(node->left);
            q.push(node->right);
        }

        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data == "#")
            return nullptr;

        stringstream ss(data);
        string p;
        ss >> p;
        TreeNode *root = new TreeNode(stoi(p));

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();

            ss >> p;
            if (p != "#")
            {
                node->left = new TreeNode(stoi(p));
                q.push(node->left);
            }

            ss >> p;
            if (p != "#")
            {
                node->right = new TreeNode(stoi(p));
                q.push(node->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));