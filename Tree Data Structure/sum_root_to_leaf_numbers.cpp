/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
# define md 1003
void trav(int &sum, TreeNode* h, int s)
{
    if(h->left==NULL && h->right==NULL)
    {sum = (sum + 10*s + h->val)%md; return;}
    
    s = (10*s + h->val)%md;
    if(h->left ) trav(sum, h->left , s);
    if(h->right) trav(sum, h->right, s);
}

int Solution::sumNumbers(TreeNode* A)
{
    int sum=0;
    trav(sum,A,0);
    return sum;
}