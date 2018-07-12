class Solution {
public:
    int height;
    vector<vector<string> > ans;
    void heightCalc(TreeNode* root, int level)
    {
        if(!root)
            return;
        height = max(height, level);
        heightCalc(root->left, level+1);
        heightCalc(root->right, level+1);
    }
    void solve(TreeNode* root, int level, int height, int pos)
    {
        if(!root)
            return;
        ans[level][pos] = to_string(root->val);
        int val = 1<<(height-level-2);
        solve(root->left, level+1, height, pos-val);
        solve(root->right, level+1, height, pos+val);    
    }
    vector<vector<string>> printTree(TreeNode* root) {
        ans.clear();
        if(!root)
            return ans;
        height = 0;
        heightCalc(root, 1);
        int col = 1<<height;
        ans.resize(height,vector<string>(col-1,""));
        int pos = col/2 - 1;
        solve(root, 0, height, pos);
        return ans;
    }
};