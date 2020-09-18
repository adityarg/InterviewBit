vector<int> Solution::solve(vector<vector<int> > &v)
{
    vector<int> ans;
    int n = (int)v.size(), m = (int)v[0].size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> index(n, 0);
    for(int i = 0; i < n; i++) pq.push({v[i][0], i});
    while(!pq.empty())
    {
        pair<int, int> p = pq.top();
        pq.pop();
        ans.push_back(p.first);
        index[p.second]++;
        if(index[p.second] < m) pq.push({v[p.second][index[p.second]], p.second});
    }
    return ans;
}