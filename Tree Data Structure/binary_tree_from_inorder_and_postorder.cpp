/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void trav(vector<int> &A, vector<int> &B, TreeNode* h, int fl)
{
    if(A.size()==0) return;
    
    int r=B.back(); B.pop_back();
    
    auto itr=A.begin();
    for(auto i=A.begin();i!=A.end();i++) if(*i==r) {itr=i;break;}
    
    vector<int> I1; for(auto i=A.begin();i!=itr;i++) I1.push_back(*i);
    vector<int> I2; for(auto i=itr+1;i!=A.end();i++) I2.push_back(*i);
    
    vector<int> P1; for(int i=0;i<I1.size();i++) P1.push_back(B[i]);
    vector<int> P2; for(int i=I1.size();i<B.size();i++) P2.push_back(B[i]);
    
    TreeNode* t=new TreeNode(r);
    if(fl) h->right=t; else h->left=t;
    
    trav(I1,P1,t,0);
    trav(I2,P2,t,1);
}

TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B)
{
    int r=B.back(); B.pop_back();
    
    auto itr=A.begin();
    for(auto i=A.begin();i!=A.end();i++) if(*i==r) {itr=i;break;}
    
    vector<int> I1; for(auto i=A.begin();i!=itr;i++) I1.push_back(*i);
    vector<int> I2; for(auto i=itr+1;i!=A.end();i++) I2.push_back(*i);
    
    vector<int> P1; for(int i=0;i<I1.size();i++) P1.push_back(B[i]);
    vector<int> P2; for(int i=I1.size();i<B.size();i++) P2.push_back(B[i]);
    
    TreeNode* root=new TreeNode(r);
    trav(I1,P1,root,0);
    trav(I2,P2,root,1);
    return root;
}