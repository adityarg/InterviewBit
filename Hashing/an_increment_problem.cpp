vector<int> Solution::solve(vector<int> &A)
{
    map<int,set<int> > m;
    vector<int> ans;
    for(int i=0;i<A.size();i++)
    {
        if(m.find(A[i])==m.end()) {m[A[i]].insert(i);}
        else
        {
            int y=*(m[A[i]].begin());
            m[A[i]].erase(m[A[i]].begin()); m[A[i]].insert(ans.size());
            m[A[i]+1].insert(y);
            ans[y]++;
        }
        ans.push_back(A[i]);
    }
    return ans;
}