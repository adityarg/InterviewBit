int Solution::minPathSum(vector<vector<int> > &A)
{
    if(A.size()==0) return 0;
    int m=A.size(),n=A[0].size(),dp[m+1][n+1];
    dp[1][1]=A[0][0];
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
        {
            if(i==1 && j==1) continue;
            if(i==1) dp[i][j]=A[i-1][j-1]+dp[i][j-1];
            else if(j==1) dp[i][j]=A[i-1][j-1]+dp[i-1][j];
            else dp[i][j]=A[i-1][j-1]+ min(dp[i][j-1],dp[i-1][j]);
        }
    return dp[m][n];
}