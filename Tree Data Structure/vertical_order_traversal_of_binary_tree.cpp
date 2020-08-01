/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A)
{
    if(A==NULL) return {};
    map<int,vector<int>> m;
    
    queue<pair<TreeNode*,int> > g;
    g.push(make_pair(A,0));
    while(!g.empty())
    {
        // cout<<"aa"<<endl;
        TreeNode* h=g.front().first;
        int temp=g.front().second;
        g.pop();
        
        m[temp].push_back(h->val);
        
        if(h->left !=NULL) g.push(make_pair(h->left ,temp-1));
        if(h->right!=NULL) g.push(make_pair(h->right,temp+1));
    }
    vector<vector<int> > v;
    for(auto i=m.begin();i!=m.end();i++) v.push_back(i->second);
    return v;
}