int Solution::cntBits(vector<int> &A)
{
    int a[A.size()][32];
    for(int i=0;i<A.size();i++)
    {
        int j=31;
        while(j>=0) {a[i][j]=A[i]%2;A[i]=A[i]/2;j--;}
    }
    long long int c=0;
    for(int j=31;j>=0;j--)
    {
        long long int o=0,e=0;
        for(int i=0;i<A.size();i++) {if(a[i][j]) o++; else e++;}
        o=o%1000000007; e=e%1000000007; o = (2*e*o)%1000000007;
        c = (c+o)%1000000007;
    }
    return (int)c;
}