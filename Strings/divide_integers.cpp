int Solution::divide(int AA, int BB)
{
    int fl=1;
    long int i=31,ans=0,B=BB,A=AA;
    if(A<0 && B<0) {A*=(-1);B*=(-1);}
    else if(A>0 && B<0) {fl=-1;B*=fl;}
    else if(A<0 && B>0) {fl=-1;A*=fl;}
    // printf("A: %ld   B: %ld\n",A,B);
    while(i>=0)
    {
        long int p=1<<i;
        // printf("%ld: %ld    ",i,p);
        if(ans+p<=A) {ans+=p;}
        i--;
        // printf("ans: %ld\n",ans);
        // printf("\n");
    }
    // printf("fl:%d\n",fl);
    ans*=fl;
    if(ans>INT_MAX || ans<INT_MIN) return INT_MAX;
    return ans;
}