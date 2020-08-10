int Solution::solve(vector<vector<int> > &A)
{
    int n=A.size();
    int dp[n][n],m=A[0][0];
    for(int i=0;i<n;i++) dp[0][i]=A[0][i];
    for(int i=1;i<n;i++)
    {
        dp[i][0]=A[i][0]+dp[i-1][0];
        m=max(m,dp[i][0]);
        for(int j=1;j<n;j++)
        {
            dp[i][j]=A[i][j]+max(dp[i-1][j],dp[i-1][j-1]);
            m=max(m,dp[i][j]);
        }
    }
    return m;
}