int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B)
{
    int s1=0,s2=0,n=A.size();
    for(int i=0;i<n;i++) {s1+=A[i]; s2+=B[i];}
    
    if(s1<s2) return -1;
    s1=0; s2=0;
    for(int i=0;i<n;i++)
    {
        s1+=A[i]-B[i];
        if(s1<=0) {s1=0;s2=(i+1)%n;}
    }
    return s2;
}