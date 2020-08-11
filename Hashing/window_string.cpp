string Solution::minWindow(string A, string T)
{
    string ans;
    map<char,int> m2;
    for(int i=0;i<T.size();i++) m2[T[i]]++;
    
    int i=0,j=0,x=INT_MAX-2,y=-1,fl=0;
    while(i<A.size())
    {
        if(fl) m2[A[j-1]]++;   else m2[A[i]]--;
        
        fl=1;
        for(auto k=m2.begin();k!=m2.end();k++)
        {
            char c=k->first; int b=k->second;
            if(b>0) {fl=0;break;}
        }
        
        if(fl && x-y+1>i-j+1) {y=j; x=i;}
        if(fl) j++;   else i++;
    }
    fl=0;
    while(j<i)
    {
        if(fl) m2[A[j-1]]++;
        
        fl=1;
        for(auto k=m2.begin();k!=m2.end();k++)
        {
            char c=k->first; int b=k->second;
            if(b>0) {fl=0;break;}
        }
        
        if(fl && x-y+1>i-j) {y=j; x=i-1;}
        if(fl) j++;   else break;
    }
    // printf("%d %d\n",y,x);
    if(y!=-1) for(int i=y;i<=x;i++) ans.push_back(A[i]);
    return ans;
}