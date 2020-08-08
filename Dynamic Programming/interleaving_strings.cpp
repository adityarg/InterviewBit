// dp[i][j] = 1 ----> means A(0...i-1) and B(0...j-1) can form C(0...i+j-1)
// dp[i][j] = 0 ----> CANNOT form string C

int Solution::isInterleave(string A, string B, string C)
{
    // Create a 2d array for storing DP
    int dp[A.size()+1][B.size()+1]={0};
    //Initialize first row
    int fl=1;
    for(int i=1;i<=B.size();i++)
    {
        if(fl && B[i-1]==C[i-1]) dp[0][i]=1;
        else {fl=0; dp[0][i]=0;}
    }
    //Initialize first column
    fl=1;
    for(int i=1;i<=A.size();i++)
    {
        if(fl && A[i-1]==C[i-1]) dp[i][0]=1;
        else {fl=0; dp[i][0]=0;}
    }
    
    // If i_th character of A = (i+j)th character of C, dp[i][j] = dp[i-1][j]
    // If j_th character of B = (i+j)th character of C, dp[i][j] = dp[i][j-1]
    for(int i=1;i<=A.size();i++)
        for(int j=1;j<=B.size();j++)
        {
            if(A[i-1]==C[i+j-1]) dp[i][j]=dp[i-1][j];
            if(B[j-1]==C[i+j-1] && dp[i][j]==0) dp[i][j]=dp[i][j-1];
        }
    
    return dp[A.size()][B.size()];
}