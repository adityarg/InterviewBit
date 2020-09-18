int Solution::solve(vector<int> &A, int B)
{
    priority_queue<int> g;
    for(int i=0;i<A.size();i++) g.push(A[i]);
    
    int ans=0;
    for(int i=1;i<=B;i++)
    {
        int u=g.top(); ans+=u; g.pop();
        if(u>0) g.push(u-1);
    }
    return ans;
}