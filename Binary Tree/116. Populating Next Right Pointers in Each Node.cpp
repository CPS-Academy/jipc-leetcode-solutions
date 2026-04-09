class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr)return nullptr;

        queue<Node*> q;
        q.push(root);

        while(!q.empty()) {
            int level_size = q.size();
            for(int i = 0; i < level_size; i++)
            {
                Node* node = q.front();
                q.pop();
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);

                if(i < level_size-1)node->next = q.front();
            }
        }

        return root;
    }
};
