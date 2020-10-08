vector<int> Solution::searchRange(const vector<int> &A, int B)
{
    int n=A.size(); vector<int> v;
    
    int l=0,r=n-1,mid=(l+r)/2;
    while(l<r)
    {
        if(A[mid]<B) l=mid+1;
        else if(A[mid]>B) r=mid-1;
        else
        {
            if((mid>0 && A[mid-1]!=B) || mid==0) break;
            else r=mid-1;
        }
        
        mid=(l+r)/2;
    }
    
    int y=mid;
    l=0,r=n-1,mid=(l+r)/2;
    while(l<r)
    {
        if(A[mid]<B) l=mid+1;
        else if(A[mid]>B) r=mid-1;
        else
        {
            if((mid<n-1 && A[mid+1]!=B) || mid==n-1) break;
            else l=mid+1;
        }
        
        mid=(l+r)/2;
    }
    
    if(A[mid]!=B || A[y]!=B) {v.push_back(-1); v.push_back(-1); return v;}
    else {v.push_back(y); v.push_back(mid); return v;}
}