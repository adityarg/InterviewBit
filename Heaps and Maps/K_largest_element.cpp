vector<int> Solution::solve(vector<int> &A, int B)
{
    priority_queue<int> g;
    for(int i=0;i<A.size();i++) g.push(A[i]);
    
    vector<int> v;
    for(int i=0;i<B;i++)
    {
        v.push_back(g.top()); g.pop();
    }
    return v;
}