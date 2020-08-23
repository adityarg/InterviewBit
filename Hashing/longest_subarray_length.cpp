int Solution::solve(vector<int> &A)
{
    int y=0; int c=0;
    map<int,int> m;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]) c++; else c--;
        
        if(c==1) y = max(y,i+1);
        else if(m.find(c-1)!=m.end()) y = max(y,i-m[c-1]);
        if(m.find(c)==m.end()) m.insert({c,i});
    }
    return y;
}