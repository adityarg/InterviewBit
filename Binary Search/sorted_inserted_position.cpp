int Solution::searchInsert(vector<int> &A, int B)
{
    int n=A.size();
    if(B<A[0]) return 0;
    else if(B>A[n-1]) return n;
    
    int l=0,h=n-1,mid=(l+h)/2;
    while(l<h)
    {
        if(A[mid]<B) l=mid+1;
        else if(A[mid]>B)
        {
            if((mid>0 && A[mid-1]<B) || mid==0) return mid;
            else h=mid-1;
        }
        else return mid;
        
        mid=(l+h)/2;
    }
    return mid;
}