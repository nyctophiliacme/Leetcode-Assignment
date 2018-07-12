class Solution {
public:
    TreeNode* func(vector<int> a, int l, int r)
    {
        if(l > r)
            return NULL;
        if(l == r)
            return new TreeNode(a[l]);
        int max = a[l], index = l;
        for(int i = l; i <= r; i++)
        {
            if(max < a[i])
            {
                max = a[i];
                index = i;
            }
        }
        TreeNode* root = new TreeNode(a[index]);
        root->left = func(a, l, index-1);
        root->right = func(a, index+1, r);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return func(nums, 0, nums.size()-1);
    }
};