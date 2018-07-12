class Solution {
public:
    void func(TreeLinkNode* root)
    {
        if(!root) 
            return;
        if(root->left)
        {
            root->left->next = root->right;
        }
        if(root->right)
        {
            root->right->next = root->next?root->next->left:NULL;
        }
        func(root->left);
        func(root->right);
    }
    void connect(TreeLinkNode *root) {
        if(!root) 
            return;
        root->next = NULL;
        func(root);
    }
};