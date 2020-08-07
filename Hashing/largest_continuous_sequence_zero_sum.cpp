vector<int> Solution::lszero(vector<int> &A)
{
    int n=A.size(),l[n],s=0;
    for(int i=0;i<n;i++) {s+=A[i];l[i]=s;}
    map<int,int> m;
    int x=0,y=-1;
    for(int i=0;i<n;i++)
    {
        auto itr=m.find(l[i]);
        if(l[i]==0)
        {
            if(y-x+1<i+1) {x=0;y=i;}
            m.insert(make_pair(l[i],i));
        }
        else if(itr!=m.end())
        {
            if(y-x+1<i-itr->second) {x=itr->second+1;y=i;}
        }
        else m.insert(make_pair(l[i],i));
        // printf("^^ %d-> x:%d  y:%d\n",m.size(),x,y);
    }
    // printf("x: %d; y: %d\n",x,y);
    vector<int> v;
    if(x!=-1) for(int j=x;j<=y;j++) v.push_back(A[j]);
    return v;
}