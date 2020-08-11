int Solution::lis(const vector<int> &A)
{
    int dp[A.size()]; dp[0]=1; int M=1;
    for(int i=1;i<A.size();i++)
    {
        int j=0,m=0;
        while(j<i)
        {
            if(A[j]<A[i]) m=max(m,dp[j]);
            j++;
        }
        dp[i]=m+1; M=max(M,dp[i]);
    }
    return M;
}