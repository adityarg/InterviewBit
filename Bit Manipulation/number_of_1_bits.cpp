int Solution::numSetBits(unsigned int A)
{
    int c=0;
    while(A>0)
    {
        if(A%2) c++;
        A=A>>1;
    }
    return c;
}