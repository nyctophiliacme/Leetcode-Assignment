class Solution {
public:
    void func(TreeNode* root)
    {
        if(!root)
            return;
        TreeNode* leftNode = root->left;
        TreeNode* rightNode = root->right;
        root->left = rightNode;
        root->right = leftNode;
        func(root->left);
        func(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        func(root);
        return root;
    }
};