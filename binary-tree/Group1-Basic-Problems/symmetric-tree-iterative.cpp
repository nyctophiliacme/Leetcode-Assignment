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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        queue<TreeNode*> q;
        TreeNode *root1, *root2;
        if(root->left && root->right)
        {
            q.push(root->left);
            q.push(root->right);
        }
        else if(root->left || root->right)
        {
            return false;
        }
        while(!q.empty())
        {
            root1 = q.front();q.pop();
            root2 = q.front();q.pop();
            if(root1->val != root2->val)
                return false;
            if(root1->left && root2->right)
            {
                q.push(root1->left);
                q.push(root2->right);
            }
            else if(root1->left || root2->right)
            {
                return false;
            }
            if(root1->right && root2->left)
            {
                q.push(root1->right);
                q.push(root2->left);
            }
            else if(root1->right || root2->left)
            {
                return false;
            }
        }
        return true;
    }
};