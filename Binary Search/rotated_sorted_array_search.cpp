int Solution::search(const vector<int> &A, int B)
{
    int n=A.size();
    
    if(A[0]<A[n-1])
    {
        auto t=lower_bound(A.begin(),A.end(),B);
        if(t==A.end()) return -1;
        else return (int)(t-A.begin());
    }
    
    int l=0,r=n-1,mid=(l+r)/2;
    while(l<r)
    {
        // cout<<l<<" "<<r<<", "<<mid<<" --> "<<A[mid]<<endl;
        if(A[mid]<A[n-1]) r=mid-1;
        else if(A[mid]>A[n-1])
        {
            if(A[mid+1]<A[n-1]) break;
            else l=mid+1;
        }
        
        mid=(l+r)/2;
    }
    // cout<<l<<" "<<r<<", "<<mid<<" --> "<<A[mid]<<endl;
    // cout<<A[mid]<<endl;
    
    l=0; r=mid; int m=(l+r)/2;
    while(l<r)
    {
        // cout<<l<<" "<<r<<", "<<m<<" --> "<<A[m]<<endl;
        if(A[m]>B) r=m-1;
        else if(A[m]<B) l=m+1;
        else break;
        
        m=(l+r)/2;
    }
    // cout<<l<<" "<<r<<", "<<m<<" --> "<<A[m]<<endl;
    if(A[m]==B) return m;
    
    l=mid+1; r=n-1; m=(l+r)/2;
    while(l<r)
    {
        if(A[m]>B) r=m-1;
        else if(A[m]<B) l=m+1;
        else return m;
        
        m=(l+r)/2;
    }
    if(A[m]==B) return m;
    
    return -1;
}