// as we are using only current and previous row, so only 2 rows are required

int Solution::isMatch(const string A, const string B)
{
    int dp[2][B.size()+1];
    dp[0][0]=1;
    //Initialize first row
    int fl=1;
    for(int i=1;i<=B.size();i++)
    {
        if(fl && B[i-1]=='*') dp[0][i]=1;
        else {fl=0; dp[0][i]=0;}
    }
    fl=1; vector<int> v; v.push_back(1);
    for(int i=1;i<=A.size();i++)
    {
        if(fl && A[i-1]=='*') v.push_back(1);
        else {fl=0; v.push_back(0);}
    }
    
    // If i_th character of A  = j_th character of B, dp[i][j] = dp[i-1][j] || dp[i][j-1] || dp[i-1][j-1]
    for(int i=1;i<=A.size();i++)
    {
        dp[0][0]=v[i-1]; dp[1][0]=v[i];
        for(int j=1;j<=B.size();j++)
        {
            if(A[i-1]==B[j-1] || A[i-1]=='?' || B[j-1]=='?') dp[1][j]=dp[0][j-1];
            else
            {
                if(A[i-1]=='*' || B[j-1]=='*')
                    dp[1][j]= dp[1][j-1] || dp[0][j] || dp[0][j-1];
                else dp[1][j]=0;
            }
        }
        for(int k=0;k<=B.size();k++) dp[0][k]=dp[1][k];
    }
    return dp[1][B.size()];
}