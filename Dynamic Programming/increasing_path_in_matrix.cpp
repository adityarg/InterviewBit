int Solution::solve(vector<vector<int> > &A)
{
    int m=A.size(),n=A[0].size();
    int dp[m][n]; memset(dp,-1,sizeof(dp));
    dp[0][0]=1;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
        {
            if(i==0 & j==0) continue;
            if(i>0 && dp[i-1][j]!=-1 && A[i][j]>A[i-1][j])
                dp[i][j]=max(dp[i][j],1+dp[i-1][j]);
            if(j>0 && dp[i][j-1]!=-1 && A[i][j]>A[i][j-1])
                dp[i][j]=max(dp[i][j],1+dp[i][j-1]);
        }
    return dp[m-1][n-1];
}