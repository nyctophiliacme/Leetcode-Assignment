class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0;
        if(root != NULL)
        {
            if(root->left!=NULL)
            {
                if(root->left->left == NULL && root->left->right == NULL)
                {
                    ans += root->left->val;
                }
                else ans += sumOfLeftLeaves(root->left);
            }
            ans += sumOfLeftLeaves(root->right);
        }
        return ans;
    }
};