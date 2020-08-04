string Solution::solve(string A)
{
    vector<int> c(26,0);// hash map for storing frequency of characters
    queue<char> g;
    string ans;
    for(int i=0;i<A.size();i++)
    {
        c[A[i]-'a']++; g.push(A[i]);
        
        // If frequency of front character in queue is greater than 1, pop it!
        while(!g.empty() && c[g.front()-'a']>1) g.pop();
        
        if(g.empty()) ans.push_back('#');
        else ans.push_back(g.front());
    }
    if(g.empty()) ans.push_back('#');
    return ans;
}