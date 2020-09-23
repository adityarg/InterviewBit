vector<int> Solution::solve(vector<int> &A, int B) {
    int n=A.size();
    vector<int> mp(n+1);
    for(int i=0;i<n;i++)
    {
        mp[A[i]]=i;
    }
    for(int i=0;i<n && B>0;i++)
    {
        if(A[i]!=(n-i))
        {
            mp[A[i]]=mp[n-i];
            swap(A[mp[n-i]],A[i]);
            B--;
        }
    }
    return A;
}