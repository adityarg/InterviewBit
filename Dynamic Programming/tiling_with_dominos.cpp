// https://www.geeksforgeeks.org/tiling-with-dominoes/

int Solution::solve(int n)
{
    if(n%2) return 0;
    long long int A[n+1],B[n+1];
    int md=1000000007;
    A[0]=1;B[0]=0; A[1]=0;B[1]=1;
    
    for(int i=2;i<=n;i++)
    {
        A[i] = (A[i-2] + 2*B[i-1])%md;
        B[i] = (A[i-1] + B[i-2])%md;
    }
    return static_cast<int>(A[n]);
}