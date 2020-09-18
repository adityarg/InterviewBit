int Solution::solve(string A, string B, vector<string> &C)
{
    set<string> m;
    for(auto i:C) m.insert(i);
    
    queue<pair<string,int> > q;
    q.push({A,1});
    
    while(!q.empty())
    {
        auto [s,c]=q.front(); q.pop();
        
        for(int i=0;i<s.size();i++)
        {
            for(int j=0;j<26;j++)
            {
                string temp=s;
                temp[i] = 'a'+j;
                
                if(temp==B) return c+1;
                if(m.find(temp)!=m.end()) {q.push({temp,c+1}); m.erase(m.find(temp));}
            }
        }
    }
    
    return 0;
}