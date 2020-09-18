//////////////////////////// BFS ////////////////////////////////////////
int Solution::knight(int A, int B, int C, int D, int E, int F)
{
    if(C==E && D==F) return 0;
    int dp[A+1][B+1]={0};
    
    queue<pair<pair<int,int>,int> > q;
    q.push({{C,D},1});
    
    while(q.size())
    {
        if(dp[E][F]) return dp[E][F]-1;
        int x=q.front().first.first, y=q.front().first.second;
        int cost=q.front().second; q.pop();
        
        if(dp[x][y]!=0) continue;
        
        dp[x][y]=cost;
        if(x+2<=A && y+1<=B && !dp[x+2][y+1]) q.push({{x+2,y+1},cost+1});
        if(x+2<=A && y-1> 0 && !dp[x+2][y-1]) q.push({{x+2,y-1},cost+1});
        if(x-2> 0 && y+1<=B && !dp[x-2][y+1]) q.push({{x-2,y+1},cost+1});
        if(x-2> 0 && y-1> 0 && !dp[x-2][y-1]) q.push({{x-2,y-1},cost+1});
        if(x+1<=A && y+2<=B && !dp[x+1][y+2]) q.push({{x+1,y+2},cost+1});
        if(x-1> 0 && y+2<=B && !dp[x-1][y+2]) q.push({{x-1,y+2},cost+1});
        if(x+1<=A && y-2> 0 && !dp[x+1][y-2]) q.push({{x+1,y-2},cost+1});
        if(x-1> 0 && y-2> 0 && !dp[x-1][y-2]) q.push({{x-1,y-2},cost+1});
    }
    return -1;
}