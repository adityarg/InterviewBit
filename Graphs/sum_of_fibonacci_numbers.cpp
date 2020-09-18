vector<long long int> dp(101);
int sol(int A)
{
    if(A==0) return 0;
    auto t=lower_bound(dp.begin(),dp.end(),A);
    if(*t > A) t--;
    
    return 1+sol(A - *t);
}

int Solution::fibsum(int A)
{
    dp[0]=0, dp[1]=1;
    for(int i=2;i<=100;i++) dp[i]=dp[i-1]+dp[i-2];
    return sol(A);
}