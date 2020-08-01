/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A)
{
    stack<pair<TreeNode*,int> > s1,s2;
    s1.push(make_pair(A,1));
    
    vector<vector<int> > v; int ver=0;
    while(!s1.empty() || !s2.empty())
    {
        stack<pair<TreeNode*,int> >*p;
        
        if(ver%2)
        {
            if(s1.empty()) p=&s2;
            else p=&s1;
        }
        else
        {
            if(s2.empty()) p=&s1;
            else p=&s2;
        }
        
        TreeNode* h; int temp;
        h=p->top().first;
        temp=p->top().second;
        p->pop();
        
        if(ver!=temp) {vector<int> w;v.push_back(w);ver=temp;}
        v.back().push_back(h->val);
        
        if(temp%2==0)
        {
            if(h->right) s1.push(make_pair(h->right,temp+1));
            if(h->left ) s1.push(make_pair(h->left ,temp+1));
        }
        else
        {
            if(h->left ) s2.push(make_pair(h->left ,temp+1));
            if(h->right) s2.push(make_pair(h->right,temp+1));
        }
    }
    return v;
}