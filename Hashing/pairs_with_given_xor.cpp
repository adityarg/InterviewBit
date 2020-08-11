int Solution::solve(vector<int> &A, int B)
{
    map<int,int> m;
    for(int i=0;i<A.size();i++) m[A[i]]=i;
    int c=0;
    for(int i=0;i<A.size();i++)
    {
        auto t=m.find(A[i]^B);
        if(t!=m.end() && t->second!=i) c++;
    }
    return c/2;
}