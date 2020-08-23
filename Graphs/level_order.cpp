/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::levelOrder(TreeNode* A)
{
    vector<vector<int> > v; vector<int> w;
    queue<pair<TreeNode*,int> > q; q.push({A,0});
    int dep=0;
    while(!q.empty())
    {
        auto [t,d]=q.front(); q.pop();
        
        if(dep!=d) {v.push_back(w); w.clear(); dep=d;}
        w.push_back(t->val);
        
        if(t->left ) q.push({t->left ,d+1});
        if(t->right) q.push({t->right,d+1});
    }
    v.push_back(w);
    return v;
}