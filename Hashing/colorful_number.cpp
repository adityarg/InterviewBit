int Solution::colorful(int A)
{
    vector<int> v,n;
    while(A>0) {n.push_back(A%10); A=A/10;}
    reverse(n.begin(),n.end());
    int p=1;
    // for(int i=0;i<n.size()-1;i++) {p=p*n[i];v.push_back(p);}
    for(int i=0;i<n.size();i++)
    {
        p=1;
        for(int j=i;j<n.size();j++) {p=p*n[j];v.push_back(p);}
    }
    sort(v.begin(),v.end());
    int fl=1;
    for(int i=1;i<v.size();i++) if(v[i-1]==v[i]) {fl=0;break;}
    return fl;
}