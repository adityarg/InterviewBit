bool comp(vector<int> a,vector<int> b)
{
    if(a[1]<b[1]) return true;
    return false;
}

int Solution::solve(vector<vector<int> > &A)
{
    sort(A.begin(),A.end(),comp);
    int ct=1, x=A[0][0], y=A[0][1];
    
    for(int i=1;i<A.size();i++)
    {
        if(A[i][0]<=y) continue;
        y=A[i][1]; ct++;
    }
    return ct;
}