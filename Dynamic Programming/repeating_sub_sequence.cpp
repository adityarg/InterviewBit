// Same as "Longest Common Subsequence in two strings" with a condition that when A[i-1]
// is equal to B[j-1], also ensure that i is NOT equal to j
int Solution::anytwo(string A)
{
    string B=A;
    int dp[B.size()+1][A.size()+1];
    
    for(int i=0;i<=A.size();i++) dp[0][i]=0;
    for(int i=0;i<=B.size();i++) dp[i][0]=0;
    
    for(int i=1;i<=A.size();i++)
        for(int j=1;j<=B.size();j++)
        {
            // careful about indices in strings
            if(A[i-1]==B[j-1] && i!=j) dp[i][j]=1 + dp[i-1][j-1];
            else  dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    if(dp[A.size()][B.size()]>1) return 1;
    return 0;
}