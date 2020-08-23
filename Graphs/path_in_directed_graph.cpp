int dfs(vector<vector<int> > &v,vector<int> &col,int i,int A)
{
    col[i]=-1;
    if(i==A) return true;
    int ans=0;
    for(auto j:v[i]) if(col[j]==0) ans+= dfs(v,col,j,A);
    col[i]=1;
    if(ans>0) return 1;
    return 0;
}

int Solution::solve(int n, vector<vector<int> > &B)
{
    vector<vector<int> > v(n+1);
    for(int i=0;i<B.size();i++) v[B[i][0]].push_back(B[i][1]);
    
    vector<int> col(n+1,0);
    return dfs(v,col,1,n);
}