vector<vector<int> > Solution::anagrams(const vector<string> &str)
{
    map<vector<int>,vector<int> > m;
    for(int i=0;i<str.size();i++)
    {
        vector<int> w(26,0);
        for(int j=0;j<str[i].size();j++) w[str[i][j]-'a']++;
        
        m[w].push_back(i);
    }
    vector<vector<int> > ans;
    for(auto i:m)
    {
        vector<int> w;
        for(int j=0;j<i.second.size();j++) w.push_back(i.second[j]+1);
        ans.push_back(w);
    }
    return ans;
}