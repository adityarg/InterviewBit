/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode* A)
{
    queue<TreeNode*> g;
    g.push(A);
    vector<int> v;
    
    while(!g.empty())
    {
        TreeNode* h=g.front();
        g.pop();
        v.push_back(h->val);
        if(h->right) g.push(h->right);
        if(h->left ) g.push(h->left );
    }
    reverse(v.begin(),v.end());
    return v;
}