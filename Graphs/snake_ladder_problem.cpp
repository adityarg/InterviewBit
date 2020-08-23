int Solution::snakeLadder(vector<vector<int> > &A, vector<vector<int> > &B)
{
    map<int,int> lad,snk;
    for(int i=0;i<A.size();i++) lad.insert({A[i][0],A[i][1]});
    for(int i=0;i<B.size();i++) snk.insert({B[i][0],B[i][1]});
    
    vector<int> dp(101,INT_MAX);
    vector<bool> vis(101,false);
    dp[1]=0; queue<int> q; q.push(1);
    
    while(!q.empty())
    {
        int i=q.front(); q.pop();
        vis[i]=true;
        auto t1=lad.find(i),t2=snk.find(i);
        if(t1!=lad.end()) { dp[t1->second]=dp[i]; q.push(t1->second);}
        if(t2!=snk.end()) { dp[t2->second]=dp[i]; q.push(t2->second);}
        if(t1==lad.end() && t2==snk.end())
        {
            if(i<100 && !vis[i+1]) {q.push(i+1); dp[i+1]=min(dp[i+1],dp[i]+1);}
            if(i< 99 && !vis[i+2]) {q.push(i+2); dp[i+2]=min(dp[i+2],dp[i]+1);}
            if(i< 98 && !vis[i+3]) {q.push(i+3); dp[i+3]=min(dp[i+3],dp[i]+1);}
            if(i< 97 && !vis[i+3]) {q.push(i+4); dp[i+4]=min(dp[i+4],dp[i]+1);}
            if(i< 96 && !vis[i+5]) {q.push(i+5); dp[i+5]=min(dp[i+5],dp[i]+1);}
            if(i< 95 && !vis[i+6]) {q.push(i+6); dp[i+6]=min(dp[i+6],dp[i]+1);}
        }
    }
    if(vis[100]) return dp[100];
    else return -1;
}