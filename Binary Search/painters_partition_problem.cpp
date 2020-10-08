#include <numeric>

int ifPos(int T,int A,vector<int> &C)
{
    int s=0;
    for(int i=0;i<C.size();i++)
        if(s+C[i]<T) s+=C[i];
        else
        {
            if(A>0)
            {
                A--;s=C[i];
            }
            else return 0;
        }
    return 1;
}

int Solution::paint(int A, int B, vector<int> &C)
{
    int mod=10000003;
    sort(C.begin(),C.end());
    for(int i=0;i<C.size();i++) C[i]= (C[i]*B);
    int ma=0;
    for(int i=0;i<C.size();i++) ma+=C[i];

    int l=0,r=ma;
    int ans=(l+r)/2;
    while(l+1<r)
    {
        if(ifPos(ans,A,C)) r=ans-1;
        else l=ans+1;

        ans=(l+r)/2;
    }

    return ans;
}