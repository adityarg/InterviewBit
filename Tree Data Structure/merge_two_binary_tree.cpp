/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void trav(TreeNode* h,TreeNode* f)
{
    if(h==NULL && f==NULL) return;
    if(h!=NULL && f!=NULL) h->val+=f->val;
    
    if(h->left && l->left) trav(h->left,f->left);
    else if(h->left==NULL && f->left!=NULL)
    {
        TreeNode* n=new TreeNode(0);
        h->left=n; solve(h->left,l->left);
    }
    
    if(h->right && l->right) trav(h->right,f->right);
    else if(h->right==NULL && f->right!=NULL)
    {
        TreeNode* n=new TreeNode(0);
        h->right=n; solve(h->right,l->right);
    }
}

TreeNode* Solution::solve(TreeNode* A, TreeNode* B)
{
    trav(A,B);
    return A;
}