int Solution::solve(int A)
{
    int c=0;
    while(A%2==0) {c++;A=A/2;}
    return c;
}