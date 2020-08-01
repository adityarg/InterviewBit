string Solution::convert(string A, int r)
{
    if(r>=A.size()) return A;
    if(r==1) return A;
    string ans;
    int j=0;
    while(j<A.size())
    {
        ans.push_back(A[j]);
        j=j+2*(r-1);
    }
    for(int i=1;i<r-1;i++)
    {
        int j=i,fl=1;
        while(j<A.size())
        {
            ans.push_back(A[j]);
            if(fl%2) {j=j+2*(r-1-i);fl=0;}
            else {j=j+2*i;fl=1;}
        }
        // cout<<ans<<endl;
    }
    j=r-1;
    while(j<A.size())
    {
        ans.push_back(A[j]);
        j=j+2*(r-1);
    }
    return ans;
}