int Solution::numDecodings(string A)
{
    int n=A.size();
    if(n==0) return 0;
    
    long long int dp[n+1]={0}; dp[0]=1; dp[1]=1;
    if(A[0]=='0') return 0;
    
    for(int i=2;i<=n;i++)
    {
        int a=A[i-1]-'0', b=10*(A[i-2]-'0') + (A[i-1]-'0');
        if(A[i-1]!='0') dp[i]=dp[i-1];
        if(a!=b && b>=1 && b<=26) dp[i]= (dp[i]+dp[i-2])%1000000007;
    }
    return (int)dp[n];
}