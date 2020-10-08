bool ifPos(vector<int> &A, int B, int p)
{
    int s=0;
    for(int i=0;i<A.size();i++)
    {
        if(s+A[i]<=p) s+= A[i];
        else
        {
            B--;
            if(B>0)
            {
                if(A[i]<=p) s=A[i];
                else return false;
            }
            else return false;
        }
    }
    return true;
}

int Solution::books(vector<int> &A, int B)
{
    int n=A.size(),ma=0;
    if(B>n) return -1;
    for(auto i:A) ma+= i;
    
    int l=1,r=ma,m;
    while(l+1<r)
    {
        m=(l+r)/2;
        // cout<<l<<" "<<r<<", "<<m<<" --> "<<ifPos(A,B,m)<<endl;
        if(ifPos(A,B,m)) r=m;
        else l=m;
    }
    // cout<<l<<" "<<r<<", "<<m<<endl;
    return r;
}