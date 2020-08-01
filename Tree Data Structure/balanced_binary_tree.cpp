/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int solve(TreeNode* h)
{
    if(h==NULL) return 0;
    if(h->left==NULL && h->right==NULL) return 1;
    // if(h->left!=NULL && h->right==NULL) return 0;
    // if(h->left==NULL && h->right!=NULL) return 0;
    
    int c1=solve(h->left), c2=solve(h->right);
    if(c1==-1 || c2==-1) return -1;
    if(abs(c1-c2)<=1) return 1+max(c1,c2);
    return -1;
}

int Solution::isBalanced(TreeNode* A)
{
    int t= solve(A);
    if(t==-1) return 0;
    else return 1;
}