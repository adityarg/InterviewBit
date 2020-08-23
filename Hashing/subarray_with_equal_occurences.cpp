int Solution::solve(vector<int> &A, int B, int C)
{
    long long int c=0,y=0;
    map<int,int> m;
    m[0]=1;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]==B) c++;  if(A[i]==C) c--;
        if(m.find(c)!=m.end()) y+= m[c];
        m[c]++;
    }
    return y;
}