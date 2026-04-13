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
//USING HASHMAP
class Solution {
public:
    void inOrder(TreeNode* node, vector<int> &v) {
        if(!node)return;

        inOrder(node->left, v);
        v.push_back(node->val);
        inOrder(node->right, v);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> v;
        inOrder(root, v);

        map<int, int> mp;
        for(int i = 0; i < v.size(); i++)
        {
            int vx = k - v[i];
            if(mp.find(vx) != mp.end())return true;
            else mp[v[i]]++;
        }

        return false;
    }
};

//USING TWO POINTER
class Solution {
public:
    void inOrder(TreeNode* node, vector<int> &v) {
        if(!node)return;

        inOrder(node->left, v);
        v.push_back(node->val);
        inOrder(node->right, v);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> v;
        inOrder(root, v);

        // map<int, int> mp;
        int i = 0, j = v.size() - 1;
        while(i < j) {
            int sum = v[i] + v[j];

            if(sum > k)j--;
            else if (sum < k)i++;
            else return true;
        }

        return false;
    }
};

