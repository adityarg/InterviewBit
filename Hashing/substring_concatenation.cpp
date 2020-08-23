vector<int> Solution::findSubstring(string A, const vector<string> &B)
{
    map<string,int> ump;
    vector<int> ans;
    for(auto s:B) ump[s]++;
    
    int x=B[0].length(), n=B.size(), m=A.length();
    int i=0,len=n*x;
    
    string sub,sub2;
    bool flag=true;
    while(i<=m-len)
    {
        flag=true;
        map<string,int> u2=ump;
        sub=A.substr(i,len);
        for(int j=0;j<=len-x;j+=x)
        {
            sub2=sub.substr(j,x);
            if(u2.find(sub2)==u2.end()) {flag=false;break;}
            else
            {
                if(u2[sub2]>0) u2[sub2]--;
                else {flag=false;break;}
            }
        }
        if(flag) ans.push_back(i);
        i++;
    }
    return ans;
}