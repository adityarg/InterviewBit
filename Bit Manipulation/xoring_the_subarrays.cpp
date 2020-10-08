// By observation,
// If 'n' is even, ans=0
// If 'n' is odd, ans=a1^a3^a5...

int Solution::solve(vector<int> &A)
{
    if(A.size()%2==0) return 0;
    int x=0;
    for(int i=0;i<A.size();i+=2) x=x^A[i];
    return x;
}