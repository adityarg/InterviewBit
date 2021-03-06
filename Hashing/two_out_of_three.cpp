vector<int> Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C)
{
    unordered_map<int,int> vis,t;
    vector<int> P;
    for(int i=0;i<A.size();i++)
    {
        if(t[A[i]]==0)
        {
            vis[A[i]]++;
            t[A[i]]++;
        }
    }
    t.clear();
    for(int i=0;i<B.size();i++)
    {
        if(t[B[i]]==0)
        {
            vis[B[i]]++;
            t[B[i]]++;
        }
    }
    t.clear();
    for(int i=0;i<C.size();i++)
    {
        if(t[C[i]]==0)
        {
            vis[C[i]]++;
            t[C[i]]++;
        }
    }
    for (auto i : vis)
    {
        if(i.second>1)
        P.push_back(i.first);
    }
    sort(P.begin(),P.end());
    return P;
}