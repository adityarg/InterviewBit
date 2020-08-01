int Solution::findMinXor(vector<int> &A)
//after sorting A, min XOR value will of any consecutive terms
{
    sort(A.begin(),A.end());
    int m=INT_MAX;
    for(int i=0;i<A.size()-1;i++) m=min(m,A[i]^A[i+1]);
    return m;
}