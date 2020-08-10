int Solution::solve(vector<int> &val, vector<int> &wt, int cap)
{
    int n=val.size(),dp[n+1][cap+1];
    for(int i=0;i<=cap;i++) dp[0][i]=0;
    for(int i=0;i<=n;i++) dp[i][0]=0;
    
    for(int i=1;i<=n;i++)
        for(int j=1;j<=cap;j++)
        {
            if(j<wt[i-1]) dp[i][j]=dp[i-1][j];
            else
            {
                dp[i][j]=max(dp[i-1][j-wt[i-1]]+val[i-1] , dp[i-1][j]);
            }
        }
    return dp[n][cap];
}