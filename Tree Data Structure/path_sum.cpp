/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int trav(TreeNode* h, int B,int s)
{
    if(s+h->val == B && h->left==NULL && h->right==NULL) return 1;
    
    int c1=0,c2=0;
    if(h->left ) c1=trav(h->left ,B,s+h->val);
    if(h->right) c2=trav(h->right,B,s+h->val);
    return c1+c2;
}

int Solution::hasPathSum(TreeNode* A, int B)
{
    int d = trav(A,B,0);
    if(d) return 1;
    else return 0;
}