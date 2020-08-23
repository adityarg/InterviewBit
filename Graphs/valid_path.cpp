bool dfs(int &m,int &n,int x,int y,vector<vector<bool> > &vis)
{
    vis[y][x]=true;
    
    if(x==m && y==n) {return true;}
    
    bool fl=false;
    
    if(x<m && !vis[y][x+1]) fl=fl || dfs(m,n,x+1,y,vis);
    if(y<n && !vis[y+1][x]) fl=fl || dfs(m,n,x,y+1,vis);
    if(x>0 && !vis[y][x-1]) fl=fl || dfs(m,n,x-1,y,vis);
    if(y>0 && !vis[y-1][x]) fl=fl || dfs(m,n,x,y-1,vis);
    
    if(x<m && y<n && !vis[y+1][x+1]) fl=fl || dfs(m,n,x+1,y+1,vis);
    if(x<m && y>0 && !vis[y-1][x+1]) fl=fl || dfs(m,n,x+1,y-1,vis);
    if(x>0 && y<n && !vis[y+1][x-1]) fl=fl || dfs(m,n,x-1,y+1,vis);
    if(x>0 && y>0 && !vis[y-1][x-1]) fl=fl || dfs(m,n,x-1,y-1,vis);
    
    return fl;
}

string Solution::solve(int m, int n, int N, int R, vector<int> &A, vector<int> &B)
{
    vector<vector<bool> > vis(n+1,vector<bool>(m+1,false));
    for(int i=0;i<=m;i++)
        for(int j=0;j<=n;j++)
        {
            for(int k=0;k<N;k++)
                if(((A[k]-i)*(A[k]-i) + (B[k]-j)*(B[k]-j)) <= R*R)
                    {vis[j][i]=true; break;}
        }
    if(dfs(m,n,0,0,vis)) return "YES";
    else return "NO";
}