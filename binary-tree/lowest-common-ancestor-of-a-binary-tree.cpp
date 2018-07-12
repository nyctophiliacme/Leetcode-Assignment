class Solution {
public:
    vector<TreeNode*> path;
    bool findPath(TreeNode* root, int k)
    {
        if(root == NULL) return false;
        path.push_back(root);
        if(root->val == k)
            return true;
        if(findPath(root->left, k) || findPath(root->right, k))
            return true;
        path.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        path.clear(); findPath(root, p->val);
        vector<TreeNode*> a = path;
        path.clear(); findPath(root, q->val);
        vector<TreeNode*> b = path;
        int i;
        for(i = 0;i < a.size() && i < b.size(); i++)
            if(a[i]->val != b[i]->val)
                break;
        return a[i-1];
    }
};