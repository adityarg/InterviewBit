int Solution::uniquePathsWithObstacles(vector<vector<int> > &A)
{
    if(A.size()==0) return 0;
    int m=A.size(),n=A[0].size(), dp[m][n], fl=0;
    if(A[0][0]==1) return 0;
    dp[0][0]=1;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
        {
            if(i==0 && j==0) continue;
            if(A[i][j]==1) {dp[i][j]=0; continue;}
            
            if(i==0) dp[i][j]=dp[i][j-1];
            else if(j==0) dp[i][j]=dp[i-1][j];
            else dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    return dp[m-1][n-1];
}