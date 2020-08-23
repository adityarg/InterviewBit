int Solution::canJump(vector<int> &A)
{
    int pos=A.size()-1;
    for(int i=A.size()-2;i>=0;i--)
    {
        if(i+A[i]>=pos) pos=i;
    }
    return pos==0;
}