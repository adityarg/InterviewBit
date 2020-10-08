unsigned int Solution::reverse(unsigned int A)
{
    unsigned int x;
    int c=32;
    while(c>0)
    {
        x = 2*x + A%2;
        A=A/2;c--;
    }
    return x;
}