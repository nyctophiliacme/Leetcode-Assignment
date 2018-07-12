class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root)
            return;
        queue<TreeLinkNode*> q;
        TreeLinkNode* f;
        q.push(root);
        q.push(NULL);
        while(!q.empty())
        {
            f = q.front();
            q.pop();
            if(f!=NULL)
            {
                f->next = q.front();
                if(f->left)
                    q.push(f->left);
                if(f->right)
                    q.push(f->right);
            }
            else if(!q.empty())
            {
                q.push(NULL);
            }
        }
    }
};