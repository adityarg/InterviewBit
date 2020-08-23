void dfs(vector<vector<int> > &v,vector<int> &col,int i,int p,int &fl)
{
    // if(fl==1) return;
    col[i]=1;
    for(auto j:v[i])
        if(col[j]==0) dfs(v,col,j,i,fl);
        else if(p!=j) {fl=1;}
    // col[i]=1;
}

int Solution::solve(int n, vector<vector<int> > &B)
{
    vector<vector<int> > v(n);
    for(int i=0;i<B.size();i++)
        {v[B[i][0]-1].push_back(B[i][1]-1); v[B[i][1]-1].push_back(B[i][0]-1);}
    
    vector<int> col(n,0);
    int fl=0;
    for(int i=0;i<n;i++) if(col[i]==0) dfs(v,col,i,-1,fl);
    return fl;
}