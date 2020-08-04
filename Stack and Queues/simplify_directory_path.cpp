string Solution::simplifyPath(string A)
{
    stack<string> g,f;
    string ans;
    int i=0;
    while(i<A.size())
    {
        if(A[i]=='/') i++;
        else if(A[i]=='.' && A[i+1]=='.') {if(!g.empty()) g.pop();i=i+2;}
        else if(A[i]=='.') {i++;continue;}
        else
        {
            string s;
            while(i<A.size() && A[i]!='/') {s.push_back(A[i]);i++;}
            g.push(s);
        }
    }
    while(!g.empty()) {f.push(g.top()); g.pop();}
    if(f.empty()) ans.push_back('/');
    else while(!f.empty()) {ans.push_back('/'); ans.append(f.top()); f.pop();}
    
    return ans;
}