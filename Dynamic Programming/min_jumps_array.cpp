int Solution::jump(vector<int> &A)
{
    int n=A.size();
    if(n==1) return 0;
    
    int maxt=0, maxId=0, k=0;
    for(int i=0;i<n;i++)
    {
        maxt-=1;
        maxt=max(maxt, A[i]);
        if(i==n-1) return k;
        if(maxt==0) return -1;
        if(i>=maxId) maxId+=maxt, k+=1;
    }
}