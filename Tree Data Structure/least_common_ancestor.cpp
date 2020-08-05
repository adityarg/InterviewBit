/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int trav(TreeNode* h,int B,vector<int> &v)
{
    if(h==NULL) return 0;
    
    v.push_back(h->val);
    if(h->val==B) {return 1;}
    
    int c1=0,c2=0;
    if(h->left ) c1=trav(h->left ,B,v);
    if(h->right) c2=trav(h->right,B,v);
    if(c1+c2==0) v.pop_back();
    return c1+c2;
}
int Solution::lca(TreeNode* A, int B, int C)
{
    vector<int> v1; int c1=trav(A,B,v1);
    vector<int> v2; int c2=trav(A,C,v2);
    
    if(c1==0 || c2==0) return -1;
    else
    {
        int i=0,j=0;
        while(i<v1.size() && j<v2.size() && v1[i]==v2[j]) {i++;j++;}
        return v1[i-1];
    }
}