bool check(string a, string b)
{
    vector<int> c(256,0);
    for(int i=0;i<a.size();i++) {c[a[i]]++; c[b[i]]--;}
    
    for(auto i:c) if(i!=0) return false;
    return true;
}

int scram(string A, string B,map<string,int> &m)
{
    // if strings are equal no need to futher check ,as to equal string are always sramble
    if(A.compare(B)==0) return 1;
    // as we pass string of equal length so if size is 1 and not equal then obviously it is
    // false, also false if they are not anagrams
    if(A.size()<=1 || check(A,B)==0) return 0;
    
    int n=A.size();
    // store combination of A and B as "A_B" in map
    string a=A; a.push_back('_'); a.append(B);
    // if already present return
    if(m.find(a)!=m.end()) return m[a];
    
    int fl=0;
    for(int i=1;i<=n-1;i++)
    {
        // check first 'i' letters for A with first 'i' letters for B and
        // check last 'n-i' letters for A with last 'n-i' letters for B
        if((scram(A.substr(0,i),B.substr(0,i),m) && scram(A.substr(i),B.substr(i),m)) || 
        // OR, check first 'i' letters for A with last 'i' letters for B and
        // check last 'n-i' letters for A with first 'n-i' letters for B
        (scram(A.substr(0,i),B.substr(n-i),m) && scram(A.substr(i),B.substr(0,n-i),m)))
        {fl=1; break;}
    }
    
    m[a]=fl;
    return m[a];
}

int Solution::isScramble(const string A, const string B)
{
    if(A.size()!=B.size()) return 0;
    if(check(A,B)==0) return 0;
    
    map<string,int> m;
    return scram(A,B,m);
}