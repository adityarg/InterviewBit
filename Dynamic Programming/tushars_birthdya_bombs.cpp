vector<int> Solution::solve(int A, vector<int> &B)
{
    int n=B.size();
    int dp[n+1][A+1];
    
    int m=0;
    for(int i=1;i<n;i++) if(B[m]>B[i]) m=i;
    int min_kicks=A/B[m];
    
    vector<int> ans; int s=B[m]*min_kicks;
    for(int i=0;i<=m;i++)
        while(B[i]+(s-B[m])<=A && ans.size()<min_kicks) {ans.push_back(i); s=(s-B[m])+B[i];}
    
    while(min_kicks>ans.size()) ans.push_back(m);
    
    return ans;
}