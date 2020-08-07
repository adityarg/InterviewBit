/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* trav(TreeNode* h)
{
    if(h->left==NULL && h->right==NULL) return h;
    
    // Make left subtree its right subtree and left subtree as NULL
    TreeNode* l=h->left, *r=h->right;
    h->right=h->left; h->left=NULL;
    
    // Function return pre-order predecessor
    TreeNode* y;
    if(l) {y=trav(l); y->right=r;}
    // If no left subtree make 'r' as right subtree
    else h->right=r;
    
    if(r) y=trav(r);
    return y;
}

TreeNode* Solution::flatten(TreeNode* A)
{
    TreeNode* y=trav(A);
    return A;
}