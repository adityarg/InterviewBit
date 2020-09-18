int m,n;
bool dfs(vector<string> &A, string &B,int i,int x,int y)
{
    if(i+1==B.size()) return true;
    
    bool c=false;
    if( x>0  && A[x-1][y]==B[i+1]) c = c || dfs(A,B,i+1,x-1,y);
    if( y>0  && A[x][y-1]==B[i+1]) c = c || dfs(A,B,i+1,x,y-1);
    if(x<m-1 && A[x+1][y]==B[i+1]) c = c || dfs(A,B,i+1,x+1,y);
    if(y<n-1 && A[x][y+1]==B[i+1]) c = c || dfs(A,B,i+1,x,y+1);
    
    return c;
}

int Solution::exist(vector<string> &A, string B)
{
    m=A.size();
    if(m==0) return 0;
    n=A[0].size();
    
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            if(B[0]==A[i][j] && dfs(A,B,0,i,j)) return 1;
    
    return 0;
}