int Solution::largestRectangleArea(vector<int> &A)
{
    // Stacks to find nearest smaller element from either side
    stack<int> g,f;
    // vectors to stores nearest smaller element from either side
    vector<int> v,w;
    // To find left nearest smaller element
    for(int i=0;i<A.size();i++)
    {
        if(!g.empty() && A[g.top()]>=A[i])
        {
            while(!g.empty() && A[g.top()]>=A[i]) g.pop();
        }
        if(g.empty()) v.push_back(0);
        else v.push_back(g.top()+1);
        g.push(i);
    }
    // To find left nearest smaller element
    for(int i=A.size()-1;i>=0;i--)
    {
        if(!f.empty() && A[f.top()]>=A[i])
        {
            while(!f.empty() && A[f.top()]>=A[i]) f.pop();
        }
        if(f.empty()) w.push_back(A.size()-1);
        else w.push_back(f.top()-1);
        f.push(i);
    }
    reverse(w.begin(),w.end());
    // Find maximum area
    int m=INT_MIN;
    for(int i=0;i<A.size();i++) m=max(m, A[i]*(w[i]-v[i]+1) );
    return m;
}