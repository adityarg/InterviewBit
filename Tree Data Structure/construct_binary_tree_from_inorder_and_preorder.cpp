/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void trav(TreeNode* h,vector<int> &A, vector<int> &B,int fl)
{
    if(A.size()==0) return;
    int r=A[0];
    auto itr=B.begin();
    for(auto i=B.begin();i!=B.end();i++) if(*i==r) {itr=i;break;}
    
    vector<int> I1; for(auto i=B.begin();i!=itr;i++) I1.push_back(*i);
    vector<int> I2; for(auto i=itr+1;i!=B.end();i++) I2.push_back(*i);
    
    vector<int> P1; for(int i=1;i<=I1.size();i++) P1.push_back(A[i]);
    vector<int> P2; for(int i=I1.size()+1;i<A.size();i++) P2.push_back(A[i]);
    
    TreeNode* t=new TreeNode(r);
    if(fl) h->right=t;
    else h->left=t;
    
    trav(t,P1,I1,0);
    trav(t,P2,I2,1);
}

TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B)
{
    int r=A[0];
    auto itr=B.begin();
    for(auto i=B.begin();i!=B.end();i++) if(*i==r) {itr=i;break;}
    
    vector<int> I1; for(auto i=B.begin();i!=itr;i++) I1.push_back(*i);
    vector<int> I2; for(auto i=itr+1;i!=B.end();i++) I2.push_back(*i);
    
    vector<int> P1; for(int i=1;i<=I1.size();i++) P1.push_back(A[i]);
    vector<int> P2; for(int i=I1.size()+1;i<A.size();i++) P2.push_back(A[i]);
    
    TreeNode* root=new TreeNode(r);
    
    trav(root,P1,I1,0);
    trav(root,P2,I2,1);
    
    return root;
}