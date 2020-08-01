/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
void Solution::connect(TreeLinkNode* A)
{
    queue<pair<TreeLinkNode*,int> > g;
    g.push(make_pair(A,0));
    
    int ver=-1; TreeLinkNode* p=NULL;
    
    while(!g.empty())
    {
        TreeLinkNode* h=g.front().first;
        int temp=g.front().second;
        g.pop();
        
        if(ver!=temp)
        {
            if(p) {p->next=NULL;}
            p=h;
            ver=temp;
        }
        else
        {
            p->next=h;p=h;
        }
        
        if(h->left ) g.push(make_pair(h->left ,temp+1));
        if(h->right) g.push(make_pair(h->right,temp+1));
    }
}