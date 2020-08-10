int Solution::solve(vector<vector<int> > &A)
{
    int n=A.size(),dp[n],M=1;
    dp[0]=1;
    for(int i=1;i<n;i++)
    {
        int j=0,m=0;
        while(j<i)
        {
            if(A[j][1]<A[i][0]) m=max(m,dp[j]);
            j++;
        }
        dp[i]=1+m;
        M=max(M,dp[i]);
    }
    return M;
}