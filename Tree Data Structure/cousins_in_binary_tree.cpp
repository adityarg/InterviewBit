/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode* A, int B)
{
    queue<pair<TreeNode*,int> > g;
    g.push(make_pair(A,0)); int ver=-1;
    TreeNode* p=NULL;
    while(!g.empty())
    {
        if(ver==g.front().second) break;
        TreeNode* h=g.front().first;
        int temp=g.front().second;
        g.pop();
        
        if(h->left  && h->left->val==B) {p=h->right;ver=temp+1;}
        if(h->right && h->right->val==B) {p=h->left;ver=temp+1;}
        if(h->left ) g.push(make_pair(h->left ,temp+1));
        if(h->right) g.push(make_pair(h->right,temp+1));
    }
    // if(p==NULL) cout<<"aa"<<endl;
    // else cout<<"bb "<<p->val<<endl;
    // cout<<"$$ "<<ver<<" "<<g.size()<<endl;
    // while(g.front()->second!=ver) g.pop();
    vector<int> v;
    while(!g.empty())
    {
        if((p && p->val==g.front().first->val) || g.front().first->val==B) {g.pop();continue;}
        v.push_back(g.front().first->val);
        g.pop();
    }
    return v;
}