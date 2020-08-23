int dfs(vector<vector<int> > &A,vector<vector<bool> > &col,int i,int j)
{
    int m=A.size(),n=A[0].size();
    col[i][j]=true; int s=0;
    if(i>0 && !col[i-1][j] && A[i-1][j]) s+=dfs(A,col,i-1,j);
    if(j>0 && !col[i][j-1] && A[i][j-1]) s+=dfs(A,col,i,j-1);
    if(i<m-1 && !col[i+1][j] && A[i+1][j]) s+=dfs(A,col,i+1,j);
    if(j<n-1 && !col[i][j+1] && A[i][j+1]) s+=dfs(A,col,i,j+1);
    
    if(i>0 && j>0 && !col[i-1][j-1] && A[i-1][j-1]) s+=dfs(A,col,i-1,j-1);
    if(i>0 && j<n-1 && !col[i-1][j+1] && A[i-1][j+1]) s+=dfs(A,col,i-1,j+1);
    if(i<m-1 && j>0 && !col[i+1][j-1] && A[i+1][j-1]) s+=dfs(A,col,i+1,j-1);
    if(i<m-1 && j<n-1 && !col[i+1][j+1] && A[i+1][j+1]) s+=dfs(A,col,i+1,j+1);
    return s+1;
}

int Solution::solve(vector<vector<int> > &A)
{
    int m=A.size(),n=A[0].size();
    vector<vector<bool> > col(m,vector<bool>(n,false));
    
    int M=0;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            if(col[i][j]==false && A[i][j]) {M=max(M,dfs(A,col,i,j));}
    return M;
}