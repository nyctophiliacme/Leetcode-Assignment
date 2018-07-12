class Solution {
public:
    queue<TreeNode* > q;
    void func(TreeNode *root)
    {
        if(!root)
            return;
        q.push(root);
        func(root->left);
        func(root->right);
    }
    void flatten(TreeNode* root) {
        if(!root) 
            return;
        while(!q.empty())
            q.pop();
        func(root);
        TreeNode* ptr = q.front();
        q.pop();
        ptr->left = NULL;
        ptr->right = NULL;
        while(!q.empty())
        {
            ptr->right = q.front();
            q.pop();
            ptr = ptr->right;
            ptr->left = NULL;
            ptr->right = NULL;
        }
    }
};