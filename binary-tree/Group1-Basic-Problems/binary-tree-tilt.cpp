class Solution {
public:
    int func(TreeNode* root, int &tilt)
    {
        if(!root)
            return 0;
        int leftSum = func(root->left, tilt);
        int rightSum = func(root->right, tilt);
        tilt += abs(rightSum - leftSum);
        return leftSum + rightSum + root->val;
    }
    int findTilt(TreeNode* root) {
        int tilt = 0;
        func(root, tilt);
        return tilt;
    }
};