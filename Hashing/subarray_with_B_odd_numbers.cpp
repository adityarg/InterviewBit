int Solution::solve(vector<int> &A, int B)
{
    map<int,int> m;
    int cv=0,c=0;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]%2) cv++;
        if(cv==B) c++;
        
        auto t=m.find(cv-B);
        if(t!=m.end()) c+= t->second;
        
        m[cv]++;
    }
    return c;
}