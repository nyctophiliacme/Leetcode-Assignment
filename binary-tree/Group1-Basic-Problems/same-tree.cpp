/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool func(TreeNode* p, TreeNode* q)
    {
        if(p && q)
        {
            if(p->val != q->val)
                return false;
            else
                return (func(p->left, q->left) && func(p->right, q->right));
        }
        else if(p || q)
            return false;
        return true;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return func(p, q);
    }
};