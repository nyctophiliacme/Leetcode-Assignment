class Solution {
public:
    //Brute Force Solution
    void func(TreeNode* root, int &min, int &secMin)
    {
        if(root == NULL)
            return;
        if(root->val < min)
        {
            secMin = min;
            min = root->val;
        }
        else if(root->val > min && root->val < secMin)
        {
            secMin = root->val;
        }
        func(root->left, min, secMin);
        func(root->right, min, secMin);
    }
    int bruteForce(TreeNode* root)
    {
        int min = INT_MAX, secMin = INT_MAX;
        func(root, min, secMin);
        return secMin == INT_MAX ? -1 : secMin;
    }
    //This is a better solution
    int ans = INT_MAX, least;
    void solve(TreeNode* root)
    {
        if(root)
        {
            if(least < root->val && ans > root->val)
            {
                ans = root->val;
            }
            else if(least == root->val)
            {
                solve(root->left);
                solve(root->right);
            }
        }
    }
    int findSecondMinimumValue(TreeNode* root) {
        
        // return bruteForce(root);
        if(root == NULL) 
            return -1;
        least = root->val;
        solve(root);
        return ans == INT_MAX ? -1 : ans;
    }
};