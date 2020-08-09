int Solution::diffPossible(const vector<int> &A, int B)
{
    map<int,int> g;
    for(int i=0;i<A.size();i++) g.insert(make_pair(A[i],i));
    for(int i=0;i<A.size();i++)
    {
        auto itr=g.find(A[i]+B);
        if(itr!=g.end() && itr->second!=i) return 1;
    }
    return 0;
}