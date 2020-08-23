int Solution::minimumTotal(vector<vector<int> > &A)
{
    int n=A.size();
    vector<vector<int> > v;
    {
        vector<int> w; w.push_back(A[0][0]);
        v.push_back(w);
    }
    for(int i=1;i<n;i++)
    {
        vector<int> w;
        for(int j=0;j<=i;j++)
        {
            if(j==0) w.push_back(v[i-1][j]+A[i][j]);
            else if(j==i) w.push_back(v[i-1][j-1]+A[i][j]);
            else w.push_back(min(v[i-1][j-1],v[i-1][j])+A[i][j]);
        }
        v.push_back(w);
    }
    int m=INT_MAX;
    for(int i=0;i<n;i++) m=min(m,v[n-1][i]);
    return m;
}