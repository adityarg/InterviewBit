int m,n;
void dfs(vector<string> &A,vector<vector<bool> > &v,int x, int y)
{
    v[x][y]=true;
    if(x>0 && A[x-1][y]=='X' && !v[x-1][y]) dfs(A,v,x-1,y);
    if(y>0 && A[x][y-1]=='X' && !v[x][y-1]) dfs(A,v,x,y-1);
    if(x<m-1 && A[x+1][y]=='X' && !v[x+1][y]) dfs(A,v,x+1,y);
    if(y<n-1 && A[x][y+1]=='X' && !v[x][y+1]) dfs(A,v,x,y+1);
}

int Solution::black(vector<string> &A)
{
    m=A.size();
    if(m==0) return 0;
    n=A[0].size();
    
    vector<vector<bool> > v(m,vector<bool>(n,false));
    int c=0;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            if(A[i][j]=='X' && !v[i][j]) {dfs(A,v,i,j);c++;}
    return c;
}