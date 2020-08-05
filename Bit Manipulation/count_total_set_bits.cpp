int Solution::solve(int A)
// If we observe bits from rightmost side at distance i than bits get inverted after
// 2i position in vertical sequence
{
    long int c=0,t=2;A++;
    for(int i=0;i<32;i++)
    {
        c+=(t/2)*(A/t);
        if(A%t > t/2) c+= (A%t - t/2);
        t=t*2;
    }
    c=c%1000000007;
    return (int)c;
}