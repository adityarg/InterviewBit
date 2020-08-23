// https://www.geeksforgeeks.org/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum/

// The idea is, sum of S1 is j and it should be closest
// to sum/2, i.e., 2*j should be closest to sum

int Solution::solve(vector<int> &A)
{
    int sum=0,n=A.size();
    for(int i=0;i<n;i++) sum+= A[i];
    
    bool dp[n+1][sum+1];
    for(int i=0;i<=n;i++) dp[i][0]=true;
    for(int i=1;i<=sum;i++) dp[0][sum]=false;
    
    for(int i=1;i<=n;i++)
        for(int j=1;j<=sum;j++)
        {
            dp[i][j]=dp[i-1][j];
            if(j>=A[i-1]) dp[i][j] = dp[i][j] | dp[i-1][j-A[i-1]];
        }
    for(int j=sum/2;j>=0;j--)
        if(dp[n][j]) return sum-2*j;
}