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
    d=max(d,t);
    if(h->left ) trav(h->left ,t+1);
    if(h->right) trav(h->right,t+1);
}

int Solution::maxDepth(TreeNode* A)
{
    d=0;
    trav(A,1);
    return d;
}