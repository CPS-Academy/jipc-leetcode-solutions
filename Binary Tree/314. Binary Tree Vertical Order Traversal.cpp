class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if(root == nullptr)return {};

        vector<vector<int>> ans;

        map<int, vector<int>> mp;
        queue<pair<TreeNode*, int>> q;

        q.push({root, 0});

        while(!q.empty()) {
            auto [node, col] = q.front();
            q.pop();

            mp[col].push_back(node->val);

            if(node->left)q.push({node->left, col-1});
            if(node->right)q.push({node->right, col+1});
        }

        for(auto [col, columnNodes]: mp) {
            ans.push_back(columnNodes);
        }

        return ans;
    }
};
