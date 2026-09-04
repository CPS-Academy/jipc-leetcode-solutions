/*
 * LeetCode 117. Populating Next Right Pointers in Each Node II
 *
 * LOGIC:
 * A BFS with a queue solves this in O(n) space. The trick here is that once a
 * level is linked, the `next` pointers of that level ALREADY act as the queue -
 * so the current level can be walked for free while building the next one.
 *
 * 1. `curr` points at the head of the level currently being processed.
 * 2. `nH` (next head) and `nT` (next tail) build the linked list of the level
 *    below. `nH` is set once by the first child found; after that every new
 *    child is appended with `nT->next = child`, then `nT` moves forward.
 * 3. The inner while walks the whole current level through `curr = curr->next`,
 *    pushing left child then right child, which keeps the left-to-right order.
 * 4. `curr = nH` drops down to the level that was just built. When a level
 *    produces no children, `nH` stays nullptr and the outer loop ends.
 *
 * This works for the general (non-perfect) tree because it only ever attaches
 * children that actually exist, so gaps in the tree are skipped automatically.
 *
 * TIME  : O(n) - every node is visited exactly twice (once as a parent while
 *                walking its level, once as a child when it is linked).
 * SPACE : O(1) - only the curr/nH/nT pointers; no queue and no recursion.
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (root == nullptr)
            return nullptr;

        Node *curr = root;

        while (curr != nullptr)
        {
            Node *nH = nullptr;
            Node *nT = nullptr;

            // building the next level with children
            while (curr != nullptr)
            {
                if (curr->left != nullptr)
                {
                    if (nH == nullptr)
                        nH = curr->left;
                    else
                        nT->next = curr->left;
                    nT = curr->left;
                }

                if (curr->right != nullptr)
                {
                    if (nH == nullptr)
                        nH = curr->right;
                    else
                        nT->next = curr->right;
                    nT = curr->right;
                }

                curr = curr->next;
            }

            curr = nH;
        }

        return root;
    }
};