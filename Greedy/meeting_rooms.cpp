bool comp(vector<int> a,vector<int> b) { return a[0]<b[0];}

int Solution::solve(vector<vector<int> > &A)
{
    sort(A.begin(),A.end(),comp);
    // for(int i=0;i<A.size();i++) cout<<A[i][0]<<"\t"<<A[i][1]<<endl;
    multiset<int> g; g.insert(A[0][1]);
    for(int i=1;i<A.size();i++)
    {
        auto t=g.upper_bound(A[i][0]);
        if(t==g.begin()) {g.insert(A[i][1]); continue;}
        t--;
        g.erase(t); g.insert(A[i][1]);
    }
    return g.size();
}