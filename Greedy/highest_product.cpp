int Solution::maxp3(vector<int> &A)
{
    int n=A.size();
    if(n==3) return A[0]*A[1]*A[2];
    if(n==4)
        return max(max(A[0]*A[1]*A[2],A[1]*A[2]*A[3]) , max(A[0]*A[2]*A[3],A[0]*A[1]*A[3]));
    sort(A.begin(),A.end());
    int a=A[0]*A[1], b=A[n-2]*A[n-3], c=A[n-1];
    return max(a*c,b*c);
}