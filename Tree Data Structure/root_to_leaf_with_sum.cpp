/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int trav(TreeNode* h, int B,int s,vector<vector<int> >&v,vector<int>&w)
{
    if(s+h->val == B && h->left==NULL && h->right==NULL)
    {
        w.push_back(h->val);
        v.push_back(w);
        w.pop_back();
        return 1;
    }
    w.push_back(h->val);
    int c1=0,c2=0;
    if(h->left ) c1=trav(h->left ,B,s+h->val,v,w);
    if(h->right) c2=trav(h->right,B,s+h->val,v,w);
    w.pop_back();
    return c1+c2;
}

vector<vector<int> > Solution::pathSum(TreeNode* A, int B)
{
    vector<vector<int> > v;
    vector<int> w;
    int d=trav(A,B,0,v,w);
    return v;
}