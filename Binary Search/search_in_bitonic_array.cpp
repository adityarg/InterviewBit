int Solution::solve(vector<int> &A, int B)
{
    int n=A.size(),l=0,h=n-1,b;
    while(l<h)
    {
        b=(l+h)/2;
        // cout<<l<<" "<<h<<", "<<b<<" --> "<<A[b]<<endl;
        if(b<n-1 && A[b]<A[b+1]) l=b+1;
        else if(b>0 && A[b]<A[b-1]) h=b-1;
        else break;
    }
    // cout<<l<<" "<<h<<", "<<b<<" --> "<<A[b]<<endl;
    b=l;
    // cout<<A[b]<<endl;
    
    l=0; h=b;
    while(l<h)
    {
        int m=(l+h)/2;
        // cout<<l<<" "<<h<<", "<<m<<" --> "<<A[m]<<endl;
        if(A[m]>B) h=m-1;
        else if(A[m]<B) l=m+1;
        else return m;
    }
    if(A[l]==B) return l;
    // cout<<l<<" "<<h<<endl;
    
    l=b+1; h=n-1;
    while(l<h)
    {
        int m=(l+h)/2;
        if(A[m]<B) h=m-1;
        else if(A[m]>B) l=m+1;
        else return m;
    }
    if(A[l]==B) return l;
    // cout<<l<<" "<<h<<endl;
    return -1;
}