class Solution {
public:
    void inOrder(TreeNode* node, vector<int> &v) {
        if(!node) return;
        inOrder(node->left, v);
        v.push_back(node->val);
        inOrder(node->right, v);
    }

    bool isValidBST(TreeNode* root) {
        vector<int> v;
        inOrder(root, v);

        for(int i = 1; i < v.size(); i++) {
            if(v[i] <= v[i-1]) return false;
        }

        return true;
    }
};
