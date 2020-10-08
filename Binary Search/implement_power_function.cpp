int Solution::pow(int xx, int n, int d)
{
    if(xx==0) return 0;
    if(n==0) return 1;
    
    int fl;
    if(xx<0 && n%2) fl=-1;
    else fl=1;
    
    long long int res=1,x=xx;
    while(n>0)
    {
        if(n%2) res=(res*x)%d;
        x=(x*x)%d;
        n=n/2;
        // cout<<"$$ "<<res<<" "<<x<<" "<<n<<endl;
    }
    
    if(fl==-1)
    {
        res=res*(-1);
        int y=ceil(((double)res)/d);
        res=res*(-1);
        res = res + y*d;
    }
    // cout<<x<<", "<<n<<", "<<d<<" -> ";
    // cout<<(-3)%3<<endl;
    
    return res;
}