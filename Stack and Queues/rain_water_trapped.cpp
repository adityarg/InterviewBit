int Solution::trap(const vector<int> &A)
{
    // Find the nearest maximum using stack from left and right side
    stack<int> s1,s2; vector<int> v1,v2;
    for(int i=0;i<A.size();i++)
    {
        if(s1.empty()) v1.push_back(-1);
        else
        {
            while(!s1.empty() && A[s1.top()]<A[i]) s1.pop();
            if(s1.empty()) v1.push_back(-1);
            else v1.push_back(s1.top());
        }
        if(s1.empty() || (!s1.empty() && A[s1.top()]<A[i])) s1.push(i);
    }
    for(int i=A.size()-1;i>=0;i--)
    {
        if(s2.empty()) v2.push_back(-1);
        else
        {
            while(!s2.empty() && A[s2.top()]<A[i]) s2.pop();
            if(s2.empty()) v2.push_back(-1);
            else v2.push_back(s2.top());
        }
        if(s2.empty() || (!s2.empty() && A[s2.top()]<A[i])) s2.push(i);
    }
    reverse(v2.begin(),v2.end());
    
    int s=0;
    for(int i=0;i<A.size();i++)
    {
        if(v1[i]==-1 || v2[i]==-1) continue;
        s+= min(A[v1[i]],A[v2[i]])-A[i];
    }
    return s;
}