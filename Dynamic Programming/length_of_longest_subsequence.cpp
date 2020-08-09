int Solution::longestSubsequenceLength(const vector<int> &A)
{
    int n=A.size();
    int p1[n],p2[n];
    
    for(int i=0;i<n;i++)
    {
        int j=0,m=0;
        while(j<i) {if(A[j]<A[i]) m=max(m,p1[j]); j++;}
        p1[i]=1+m;
    }
    for(int i=n-1;i>=0;i--)
    {
        int j=n-1,m=0;
        while(j>i) {if(A[j]<A[i]) m=max(m,p2[j]); j--;}
        p2[i]=1+m;
    }
    int m=0;
    for(int i=0;i<n;i++) m=max(m,p1[i]+p2[i]-1);
    return m;
}