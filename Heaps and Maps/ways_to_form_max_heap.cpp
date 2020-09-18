int md=1000000007;
long long power(long long a,int x)
{
    long long res=1;
    while(x>0)
    {
        if(x%2) res=(res*a)%md;
        a=(a*a)%md;
        x=x/2;
    }
    return res;
}

int taim(int n)
{
    if(n<=2) return 1;
    n--;
    
    // // // Calculate nCy // // //
    int y=0,u=1;
    while(2*(y+u)<=n) {y+=u;u=u*2;}
    if(u>n-2*y) y+= (n-2*y);
    else y+=u;
    
    long long ans=1;
    for(int i=n-y+1;i<=n;i++) ans=(ans*i)%md;
    for(int i=1;i<=y;i++) ans=(ans*power(i,md-2))%md;
    // // // -- // // //
    
    long long a1=taim(y), b1=taim(n-y);
    ans=(ans*((a1*b1)%md))%md;
    
    return static_cast<int>(ans);
}

int Solution::solve(int n)
{
    return taim(n);
}