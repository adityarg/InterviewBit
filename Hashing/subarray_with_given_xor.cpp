int Solution::solve(vector<int> &A, int B)
{
    map<int,vector<int> > m;
    int cv=0,c=0;
    for(int i=0;i<A.size();i++)
    {
        cv=cv^A[i];
        
        auto t=m.find(cv^B);
        if(t!=m.end()) c+= t->second.size();
        if(cv==B) c++;
        
        m[cv].push_back(i);
    }
    return c;
}