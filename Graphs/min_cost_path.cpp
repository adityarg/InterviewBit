int Solution::solve(int m, int n, vector<string> &A)
{
    deque<tuple<int,int,int> > q;
    q.push_front({0, 0, 0});
    vector<vector<bool>> vis(m, vector<bool>(n, false));
    vis[0][0] = true;
    
    while(!q.empty())
    {
        auto [cost, i, j] = q.front();
        q.pop_front();
        vis[i][j] = true;
        
        if(i==m-1 and j==n-1) return cost;
    
        if(i-1>=0 and vis[i-1][j]==false)
        {
            if(A[i][j] == 'U') q.push_front({cost, i-1, j});
            else q.push_back({cost+1, i-1, j});
        }
        if(j+1<n and vis[i][j+1]==false)
        {
            if(A[i][j] == 'R') q.push_front({cost, i, j+1});
            else q.push_back({cost+1, i, j+1});
        }
        if(i+1<m and vis[i+1][j]==false)
        {
            if(A[i][j] == 'D') q.push_front({cost, i+1, j});
            else q.push_back({cost+1, i+1, j});
        }
        if(j-1>=0 and vis[i][j-1]==false)
        {
            if(A[i][j] == 'L') q.push_front({cost, i, j-1});
            else q.push_back({cost+1, i, j-1});
        }
    }
}