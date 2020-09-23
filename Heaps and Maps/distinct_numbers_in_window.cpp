vector<int> Solution::dNums(vector<int> &A, int B)
{
    int n=A.size();
    vector<int> v;
    if(B>n) return v;
    
    map<int,int> m;
    for(int i=0;i<B;i++)
    {
        m[A[i]]++;
    }
    
    v.push_back(m.size());
    for(int i=1;i<=n-B;i++)
    {
        m[A[i-1]]--; auto t=m.find(A[i-1]);
        if(m[A[i-1]]==0) m.erase(t);
        m[A[i+B-1]]++;
        v.push_back(m.size());
    }
    return v;
}