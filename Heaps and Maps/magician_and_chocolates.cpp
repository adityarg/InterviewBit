int Solution::nchoc(int A, vector<int> &B)
{
    priority_queue<int> g;
    for(int i=0;i<B.size();i++) g.push(B[i]);
    
    long int ans=0;
    for(int i=1;i<=A;i++)
    {
        int u=g.top(); g.pop();
        ans=(ans+u)%1000000007; g.push(u/2);
    }
    return static_cast<int>(ans);
}