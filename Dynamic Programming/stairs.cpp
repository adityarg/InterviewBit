int Solution::climbStairs(int A)
{
    int dp[A+1]={1};
    int i=0;
    while(i<A)
    {
        if(i+1<=A)
        {
            dp[i+1]+=dp[i];
        }
        if(i+2<=A)
        {
            dp[i+2]+=dp[i];
        }
        i++;
    }
    return dp[A];
}