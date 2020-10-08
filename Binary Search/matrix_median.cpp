int Solution::findMedian(vector<vector<int> > &A)
{
    int n=A.size(),m=A[0].size(),tot=n*m;

    int L=1,R=INT_MAX-1,ans;
    while(L<R)
    {
        ans=(L+R)/2;
        
        int c1=0,c2=0;
        for(int i=0;i<n;i++)
        {
            if(ans<A[i][0]) continue;
            int l1=(int)(lower_bound(A[i].begin(),A[i].end(),ans)-A[i].begin());
            int l2=(int)(upper_bound(A[i].begin(),A[i].end(),ans)-A[i].begin());
            c1+= l1; c2+= l2;
        }
        // cout<<L<<" "<<R<<", "<<ans<<" --> "<<"("<<c1<<", "<<c2<<")"<<endl;
        if(c2<=(tot-1)/2) L=ans+1;
        else if(c1>=(tot+1)/2) R=ans-1;
        else return ans;
    }
    
    return L;
}