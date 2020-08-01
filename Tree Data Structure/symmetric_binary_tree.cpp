/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// RECURSICE SOLUTION ///////////////////////

// bool isSymmetricHelper(TreeNode *leftTree, TreeNode *rightTree)
// {
//     if (leftTree == NULL || rightTree == NULL) return leftTree == rightTree;
//     if (leftTree->val != rightTree->val) return false;
//     return isSymmetricHelper(leftTree->left, rightTree->right) && isSymmetricHelper(leftTree->right, rightTree->left);
// }
// bool isSymmetric(TreeNode *root) {
//     return root == NULL || isSymmetricHelper(root->left, root->right);
// }

/////////////////////////////////////////////


int checkp(vector<int>&v)
{
    vector<int> w=v;
    reverse(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
        if(v[i]!=w[i]) return 1;
    return 0;
}

int Solution::isSymmetric(TreeNode* A)
{
    queue<pair<TreeNode*,int> > g;
    g.push(make_pair(A,0)); int ver=-1;
    vector<vector<int> > v;
    while(!g.empty())
    {
        TreeNode* h=g.front().first;
        int temp=g.front().second;
        g.pop();
        
        if(ver!=temp) {vector<int> w;v.push_back(w); ver=temp;}
        if(h) v.back().push_back(h->val);
        else v.back().push_back(-1);
        
        if(h) g.push(make_pair(h->left ,temp+1));
        if(h) g.push(make_pair(h->right,temp+1));
    }
    int fl=1;
    for(int i=0;i<v.size();i++)
        if(checkp(v[i])) {fl=0;break;}
    return fl;
}