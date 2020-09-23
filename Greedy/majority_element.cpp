int Solution::majorityElement(const vector<int> &A)
{
    map<int,int> m; int n=A.size();
    for(int i=0;i<n;i++)
    {
        auto t=m.find(A[i]);
        if(t==m.end()) m[A[i]]=1;
        else m[A[i]]++;
    }
    for(auto i=m.begin();i!=m.end();i++)
    {
        if(i->second>(n/2)) return i->first;
    }
    return -1;
}