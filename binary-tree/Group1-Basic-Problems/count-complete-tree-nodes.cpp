class Solution {
public:
    int leftHeight(TreeNode* root)
    {
        int height = 0;
        while(root)
        {
            root = root->left;
            height++;
        }
        return height;
    }
    int rightHeight(TreeNode* root)
    {
        int height = 0;
        while(root)
        {
            root = root->right;
            height++;
        }
        return height;
    }
    int countNodes(TreeNode* root) {
        int left = leftHeight(root);
        int right = rightHeight(root);
        if(left == right)
            return (1<<left)-1; 
        else
            return countNodes(root->left) + countNodes(root->right) + 1;
    }
};