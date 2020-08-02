/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int d;
void trav(TreeNode* h,int t)
{
    if(h->left ) trav(h->left ,t+1);
    if(h->right) trav(h->right,t+1);
    
    if(h->left==NULL && h->right==NULL)
    {
        d=min(d,t);
    }
}

int Solution::minDepth(TreeNode* A)
{
    d=INT_MAX;
    trav(A,1);
    return d;
}