int cnt;
void dfs(vector<int> &A,vector<vector<int> > &v,vector<int> &col,int i,int p,int h,int C)
{
    col[i]=1;
    if(v[i].size()==1) if(h<=C) cnt++;
    
    for(auto j:v[i])
        if(col[j]==0)
        {
            if(A[j]) dfs(A,v,col,j,i,h+1,C);
            else dfs(A,v,col,j,i,h,C);
        }
}

int Solution::solve(vector<int> &A, vector<vector<int> > &B, int C)
{
    int n=A.size();
    vector<vector<int> > v(n);
    for(int i=0;i<B.size();i++)
        {v[B[i][0]-1].push_back(B[i][1]-1); v[B[i][1]-1].push_back(B[i][0]-1);}
    
    vector<int> col(n,0);
    cnt=0;
    dfs(A,v,col,0,-1,A[0],C);
    return cnt;
}