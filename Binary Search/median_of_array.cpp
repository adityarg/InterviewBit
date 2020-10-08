double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B)
{
    int n=A.size(),m=B.size();
    if(n>m) return findMedianSortedArrays(B,A);
    
    if(n==0)
    {
        if(m%2) return B[m/2];
        else return (B[m/2]+(double)B[m/2-1])/2;
    }
    
    int l=0,r=n,i=(l+r)/2,j=(m+n+1)/2-i;
    while(l<r)
    {
        if(i==0)
        {
            if(B[j-1]<=A[i]) break;
            else l=i+1;
        }
        else if(i==n)
        {
            if(A[i-1]<=B[j]) break;
            else r=i-1;
        }
        else
        {
            if(A[i-1]<=B[j] && B[j-1]<=A[i]) break;
            else if(A[i-1]>B[j]) r=i-1;
            else l=i+1;
        }
        
        i=(l+r)/2;
        j=(m+n+1)/2-i;
    }
    
    if((m+n)%2)
    {
        if(i==0) return B[j-1];
        else return max(A[i-1],B[j-1]);
    }
    else
    {
        double a,b;
        if(i==0) {a=min(A[i],B[j]); b=B[j-1];}
        else if(i==n) {a=B[j]; b=max(A[i-1],B[j-1]);}
        else {a=min(A[i],B[j]), b=max(A[i-1],B[j-1]);}
        return (a+b)/2;
    }
}