void lpsArray(int* lps,string pat)
{
    int n=pat.size(),len=0;
    lps[0]=0;
    int i=1;
    while(i<n)
    {
        if(pat[i]==pat[len]) {lps[i]=len+1;len++;i++;}
        else
        {
            if(len==0) {lps[i]=0;i++;}
            else len=lps[len-1];
        }
    }
}

int Solution::solve(string A)
{
    int n=A.size();
    string S=A; reverse(S.begin(),S.end());
    A=S+"$"+A;
    int lps[A.size()];
    lpsArray(lps,A);
    return n-lps[A.size()-1];
}