// https://www.geeksforgeeks.org/count-distinct-occurrences-as-a-subsequence/
int Solution::numDistinct(string A, string B)
{
    if(A.size()<B.size()) return 0;
    
    int dp[A.size()+1][B.size()+1]={0};
    for(int i=0;i<=A.size();i++) dp[i][0]=1;
    for(int i=1;i<=B.size();i++) dp[0][i]=0;
    
    for(int i=1;i<=A.size();i++)
        for(int j=1;j<=B.size();j++)
        {
            // If last characters don't match, then value is same as
            // the value without last character in main string.
            if(A[i-1]!=B[j-1]) dp[i][j]=dp[i-1][j];
            // Else value is obtained considering two cases. 
            // a) All substrings without last character in main string 
            // b) All substrings without last characters in both.
            else dp[i][j]= dp[i-1][j] + dp[i-1][j-1];
        }
    return dp[A.size()][B.size()];
}