int Solution::lengthOfLongestSubstring(string A)
{
    map<char,int> m;
    int i=0,j=0,l=1;
    while(i<A.size())
    {
        if(m.find(A[i])==m.end()) m[A[i]]=i;
        else
        {
            if(j<=m[A[i]]) j=m[A[i]]+1;
            m[A[i]]=i;
        }
        l=max(l,i-j+1);i++;
        // printf("%d %d %d %c\n",i,j,l,A[i]); i++;
    }
    return l;
}