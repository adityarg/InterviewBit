int maxi(int a,int b,int c)
{
    return max(max(abs(a-b) , abs(b-c)) , abs(c-a));
}

int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C)
{
    int m=INT_MAX,i=0,j=0,k=0;
    while(i<A.size() && j<B.size() && k<C.size())
    {
        m = min( m , maxi(A[i],B[j],C[k]) );
        if(A[i]<=B[j] && A[i]<=C[k]) i++;
        else if(B[j]<=A[i] && B[j]<=C[k]) j++;
        else k++;
    }
    return m;
}