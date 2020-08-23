int Solution::solve(const vector<int> &A)
{
    map<pair<int,int>, int> m;
    int n=A.size();
    for(int i=1;i<n;i++)
    {
        int j=0;
        while(j<i)
        {
            auto t=m.find({j,A[i]-A[j]});
            if(t==m.end()) m[{i,A[i]-A[j]}] = 2;
            else m[{i,A[i]-A[j]}] = t->second+1;
            j++;
        }
    }
    int M=1;
    for(auto t:m) M=max(M,t.second);
    return M;
}