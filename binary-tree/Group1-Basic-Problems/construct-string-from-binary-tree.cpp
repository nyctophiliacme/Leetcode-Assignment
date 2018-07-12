class Solution {
public:
    string s;
    void func(TreeNode* t)
    {
        if(!t)
            return;
        s += to_string(t->val);
        if(t->left)
        {
            s += '(';
            func(t->left);
            s+=')';
            if(t->right)
            {
                s += '(';
                func(t->right);
                s+=')';
            }
        }
        else if(t->right)
        {
            s += "()(";
            func(t->right);
            s+=')';
        }
    }
    string tree2str(TreeNode* t) {
        s = "";
        func(t);
        return s;
    }
};