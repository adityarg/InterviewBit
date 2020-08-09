int Solution::isMatch(const string B, const string A)
{
    if(A==B) return 1;
    int dp[A.size()+1][B.size()+1];
    dp[0][0]=1;
    //Initialize first row
    int fl=1;
    for(int i=1;i<=B.size();i++) dp[0][i]=0;
    dp[1][0]=0;
    for(int i=2;i<=A.size();i++)
    {
        if(A[i-1]!='*' && A[i-2]!='*') fl=0;
        
        if(fl && A[i-1]=='*') dp[i][0]=1;
        else dp[i][0]=0;
    }
    // char 'c' to track preceding character
    char c='\0';
    for(int i=1;i<=A.size();i++)
    {
        for(int j=1;j<=B.size();j++)
        {
            if(A[i-1]==B[j-1] || A[i-1]=='.') {dp[i][j]=dp[i-1][j-1];}
            else
            {
                if(A[i-1]=='*' && (c==B[j-1]|| c=='.'))
                    dp[i][j]= dp[i][j-1] || dp[i-1][j] || dp[i-1][j-1] || dp[i-2][j];
                else if(A[i-1]=='*') dp[i][j]=dp[i-2][j];
                else {dp[i][j]=0;}
            }
        }
        c=A[i-1];
    }
    return dp[A.size()][B.size()];
}