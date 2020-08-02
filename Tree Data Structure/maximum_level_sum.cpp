/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::solve(TreeNode* A)
{
    queue<pair<TreeNode*,int> > g;
    g.push(make_pair(A,0)); int ver=-1,s=0;
    vector<int> v;
    while(!g.empty())
    {
        TreeNode* h=g.front().first;
        int temp=g.front().second;
        g.pop();
        
        if(ver!=temp) {v.push_back(s);s=0;ver=temp;}
        
        s+=h->val;
        if(h->left ) g.push(make_pair(h->left ,temp+1));
        if(h->right) g.push(make_pair(h->right,temp+1));
    }
    v.push_back(s);
    int m=0;
    for(int i=1;i<v.size();i++) m=max(m,v[i]);
    return m;
}