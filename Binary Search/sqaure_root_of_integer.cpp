int Solution::sqrt(int A)
{
    long long int ans=A/2,l=1,r=A;
    // printf("aa\n");
    while(!(ans*ans<=A && (ans+1)*(ans+1)>A))
    {
        // printf("%d ",ans);
        if(ans*ans<=A) l=ans+1;
        else if(ans*ans>A) r=ans-1;
        // printf("%d\n",ans);
        ans=(l+r)/2;
    }
    return ans;
}