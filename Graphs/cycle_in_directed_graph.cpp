int fl;

void dfs(vector<vector<int> > &v,vector<int> &col,int i)
{
    col[i]=-1;
    for(auto j:v[i])
    {
        if(col[j]==0) {dfs(v,col,j);}
        else if(col[j]==-1) {fl=1;}
    }
    
    col[i]=1;
}

int Solution::solve(int n, vector<vector<int> > &B)
{
    vector<vector<int> > v(n+1);
    for(int i=0;i<B.size();i++) v[B[i][0]].push_back(B[i][1]);
    
    vector<int> col(n+1,0);
    fl=0;
    for(int i=1;i<=n;i++)
    {
        if(col[i]==0) {dfs(v,col,i);}
        if(fl) break;
    }
    return fl;
}