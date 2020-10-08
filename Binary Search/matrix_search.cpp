int Solution::searchMatrix(vector<vector<int> > &A, int B)
{
    int n=A.size(),m=A[0].size();
    
    int l=0,r=n-1,mid=(l+r)/2;
    while(l<r)
    {
        if(A[mid][0]>B) r=mid-1;
        else if(A[mid][m-1]<B) l=mid+1;
        else break;
        
        mid=(l+r)/2;
    }
    
    int y=mid;
    l=0; r=m-1; mid=(l+r)/2;
    while(l<r)
    {
        if(A[y][mid]>B) r=mid-1;
        else if(A[y][mid]<B) l=mid+1;
        else break;
        
        mid=(l+r)/2;
    }
    if(A[y][mid]==B) return 1;
    else return 0;
}