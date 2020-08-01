int Solution::divide(int AA, int BB)
{
    if(AA==INT_MIN && BB==-1) return INT_MAX;
    int fl=1; long long int B=BB,A=AA;
    
    if(A<0 && B<0) {A*=(-1);B*=(-1);}
    else if(A>0 && B<0) {fl=-1;B*=fl;}
    else if(A<0 && B>0) {fl=-1;A*=fl;}
    
    int ans=0;
    while(A>=B)
    {
        long long int temp=B,x=1;
        while((temp<<1)<=A) {temp=temp<<1;x=x<<1;}
        A-=temp;
        ans+=x;
    }
    ans*=fl;
    // if(ans>INT_MAX || ans<INT_MIN) return INT_MAX;
    return ans;
}