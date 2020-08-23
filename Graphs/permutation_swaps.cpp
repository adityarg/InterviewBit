typedef struct subset {int parent,rank;} robo;

int find(robo* w,int i)
{
    if(w[i].parent!=i) w[i].parent=find(w,w[i].parent);
    return w[i].parent;
}

void Union(robo* w,int x,int y)
{
    int p1=find(w,x);
    int p2=find(w,y);
    if(w[p1].rank>w[p2].rank) w[p2].parent=p1;
    else if(w[p1].rank<w[p2].rank) w[p1].parent=p2;
    else {w[p2].parent=p1; w[p1].rank++;}
}

void dfs(vector<vector<int> > &v,vector<int> &col,vector<int> &A,robo *w,int i)
{
    col[i]=1;
    for(auto j:v[i])
        if(col[j]==0) {Union(w,A[i],A[j]); dfs(v,col,A,w,j);}
}

int Solution::solve(vector<int> &A, vector<int> &B, vector<vector<int> > &C)
{
    int n=A.size();
    vector<vector<int> > v(n);
    for(int i=0;i<C.size();i++)
        {v[C[i][0]-1].push_back(C[i][1]-1); v[C[i][1]-1].push_back(C[i][0]-1);}
    
    robo w[n];
    for(int i=1;i<=n;i++) {w[i].parent=i; w[i].rank=0;}
    
    //// DFS traversal to find disjoint sets of elts of 'A' using good pairs ////
    vector<int> col(n,0);
    for(int i=0;i<n;i++) if(col[i]==0) dfs(v,col,A,w,i);
    /////////////////////////////////////////////////////////////////////////////
    
    //// If i_th elt of 'A' and 'B' lie in same set then they can be swapped ////
    for(int i=0;i<n;i++)
    {
        if(A[i]!=B[i])
        {
            int a=find(w,A[i]),b=find(w,B[i]);
            if(a!=b) return 0;
        }
    }
    return 1;
}