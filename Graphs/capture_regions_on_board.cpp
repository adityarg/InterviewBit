int fl,m,n;
void dfs(vector<vector<char> > &A,vector<vector<bool> > &vis,int x,int y)
{
    vis[x][y]=true;
    if(x==0 || y==0 || x==m-1 || y==n-1) fl=1;
    if( x>0  && A[x-1][y]=='O' && !vis[x-1][y]) dfs(A,vis,x-1,y);
    if( y>0  && A[x][y-1]=='O' && !vis[x][y-1]) dfs(A,vis,x,y-1);
    if(x<m-1 && A[x+1][y]=='O' && !vis[x+1][y]) dfs(A,vis,x+1,y);
    if(y<n-1 && A[x][y+1]=='O' && !vis[x][y+1]) dfs(A,vis,x,y+1);
}

void init(vector<vector<char> > &A,vector<vector<bool> > &vis,int x,int y)
{
    vis[x][y]=true;
    A[x][y]='X';
    if( x>0  && A[x-1][y]=='O' && !vis[x-1][y]) init(A,vis,x-1,y);
    if( y>0  && A[x][y-1]=='O' && !vis[x][y-1]) init(A,vis,x,y-1);
    if(x<m-1 && A[x+1][y]=='O' && !vis[x+1][y]) init(A,vis,x+1,y);
    if(y<n-1 && A[x][y+1]=='O' && !vis[x][y+1]) init(A,vis,x,y+1);
}

void Solution::solve(vector<vector<char> > &A)
{
    m=A.size();
    if(m==0) return;
    n=A[0].size();
    
    vector<vector<bool> > vis(m,vector<bool>(n,false));
    vector<pair<int,int> > w;
    
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
        {
            if(A[i][j]=='O' && !vis[i][j])
            {
                fl=0; dfs(A,vis,i,j);
                if(fl==0) w.push_back({i,j});
            }
        }
    vector<vector<bool> > bla(m,vector<bool>(n,false));
    for(int k=0;k<w.size();k++)
    {
        int i=w[k].first, j=w[k].second;
        if(A[i][j]=='O' && !bla[i][j]) init(A,bla,i,j);
    }
}