// https://www.geeksforgeeks.org/edit-distance-dp-5/
int Solution::minDistance(string A, string B)
{
    int dp[B.size()+1][A.size()+1];
    
    for(int i=0;i<=A.size();i++) dp[0][i]=i;
    for(int i=0;i<=B.size();i++) dp[i][0]=i;
    
    for(int i=1;i<=B.size();i++)
        for(int j=1;j<=A.size();j++)
        {
            // careful about indices in strings
            if(B[i-1]==A[j-1]) dp[i][j]=dp[i-1][j-1];
            else  dp[i][j] = 1+min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]);
        }
    return dp[B.size()][A.size()];
}