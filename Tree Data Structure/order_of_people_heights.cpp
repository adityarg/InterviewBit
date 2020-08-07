TreeNode *build_st(int ss,int se,int value){
    if(ss==se){
        return new TreeNode(value);
    }
    TreeNode *node=new TreeNode(value);
    int mid=(ss+se)/2;
    TreeNode *le,*ri;
    le=build_st(ss,mid,value);
    ri=build_st(mid+1,se,value);
    
    node->val=le->val+ri->val;
    node->left=le;
    node->right=ri;
    
    return node;
}

int query(TreeNode *node,int ss,int se,int pos){
    
   if(ss==se){
       return ss;
   }
   
   int mid=(ss+se)/2;
   
   if(node->left->val>=pos){
       return query(node->left,ss,mid,pos);
   }
   else{
       pos=pos-node->left->val;
       return query(node->right,mid+1,se,pos);
   }
    
}

void update(TreeNode *node,int ss,int se,int pos){
    if(node==NULL){
        return;
    }
    
    if(pos<ss || pos>se){
        return;
    }
    
    if(ss==se){
        node->val--;
        return;
    }
    
    int mid=(ss+se)/2;
    update(node->left,ss,mid,pos);
    update(node->right,mid+1,se,pos);
    node->val--;
    
    return;
}

vector<int> Solution::order(vector<int> &A, vector<int> &B) {
    int n=A.size();
    
    TreeNode *root;
    
    root=build_st(0,n-1,1);
    
    vector<int> ans(n);
    
    map<int,int> m;
    
    for(int i=0;i<n;i++){
        m[A[i]]=B[i];
    }
    
    for(auto it:m){
        
        int pos=query(root,0,n-1,it.second+1);
    //    cout<<pos<<" "<<it.first<<" "<<it.second<<"\n";
        ans[pos]=it.first;
        update(root,0,n-1,pos);
    }
    return ans;
}