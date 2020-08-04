/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void trav(TreeNode* h,vector<int>v,int fl)
{
    if(v.size()==0) return;
    
    auto itr=v.begin() + v.size()/2;
    vector<int> v1; for(auto i=v.begin();i!=itr;i++) v1.push_back(*i);
    vector<int> v2; for(auto i=itr+1;i!=v.end();i++) v2.push_back(*i);
    
    TreeNode* t=new TreeNode(*itr);
    if(fl) h->right=t; else h->left=t;
    
    trav(t,v1,0);
    trav(t,v2,1);
}

TreeNode* Solution::sortedArrayToBST(const vector<int> &A)
{
    auto itr=A.begin() + A.size()/2;
    vector<int> v1; for(auto i=A.begin();i!=itr;i++) v1.push_back(*i);
    vector<int> v2; for(auto i=itr+1;i!=A.end();i++) v2.push_back(*i);
    
    TreeNode* root=new TreeNode(*itr);
    
    trav(root,v1,0);
    trav(root,v2,1);
    return root;
}