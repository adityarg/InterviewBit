int Solution::solve(vector<int> &A)
{
    map<int,pair<int,int> > m;
    for(int i=0;i<A.size();i++)
    {
        if(m.find(A[i])==m.end()) m.insert({ A[i] , {i,0} });
        else
        {
            m[A[i]].second=-1;
        }
    }
    int n=INT_MAX,fl=0;
    for(auto i:m)
    {
        if(i.second.second==-1) {n=min(n,i.second.first);fl=1;}
    }
    if(fl==0) return -1;
    else return A[n];
}