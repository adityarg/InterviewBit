vector<int> Solution::solve(vector<int> &A, vector<int> &B)
{
    int n=A.size();
    sort(A.begin(),A.end()); sort(B.begin(),B.end());
    map<pair<int,int>,int> m;
    priority_queue <pair<int, pair<int, int> > > g;
    vector<int> ans;
    
    m.insert({{n-1,n-1},1});
    g.push({A[n-1]+B[n-1],{n-1,n-1}});
    for(int i=1;i<=n;i++)
    {
        int L=g.top().second.first, R=g.top().second.second, yt=g.top().first; g.pop();
        ans.push_back(yt);
        
        if(m.find({L,R-1})==m.end())
        {
            g.push({A[L]+B[R-1],{L,R-1}});
            m.insert({{L,R-1},1});
        }
        if(m.find({L-1,R})==m.end())
        {
            g.push({A[L-1]+B[R],{L-1,R}});
            m.insert({{L-1,R},1});
        }
    }
    return ans;
}