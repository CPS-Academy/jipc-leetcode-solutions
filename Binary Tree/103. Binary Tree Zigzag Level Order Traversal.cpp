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
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr)return ans;

        queue<TreeNode*> q;
        q.push(root);

        int cnt = 0;

        while(!q.empty()) {
            int sz = q.size();
            vector<int> v;
            for(int i = 0; i < sz; i++)
            {
                TreeNode* tmp = q.front();
                q.pop();
                if(tmp->left)q.push(tmp->left);
                if(tmp->right)q.push(tmp->right);
                v.push_back(tmp->val);
            }
            if(cnt%2)reverse(v.begin(), v.end());
            cnt++;
            ans.push_back(v);
        }

        return ans;
    }
};
