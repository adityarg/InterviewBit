int Solution::singleNumber(const vector<int> &A)
{
    int n=A.size(),x=0;
    for(int j=0;j<=31;j++)
    {
        int o=0;
        for(int i=0;i<n;i++)
            if((A[i]>>(31-j))%2) o++;
        if(o%3) x = x*2 + 1;
        else x = x*2 + 0;
    }
    return x;
}