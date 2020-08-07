vector<int> Solution::twoSum(const vector<int> &A, int B)
{
    map<int,int> m;
    for(int i=0;i<A.size();i++)
    {
        auto itr=m.find(A[i]);
        if(itr==m.end()) m[A[i]]=i;
    }
    // cout<<m.size()<<endl<<endl;
    int x=INT_MAX,y=INT_MAX,fl=-1;
    for(int i=0;i<A.size();i++)
    {
        auto itr=m.find(B-A[i]);
        // printf("%d -> ",B-A[i]);
        if(itr!=m.end() && itr->second!=i)
        {
            int a=min(i,itr->second),b=max(i,itr->second);
            if(fl==-1) {y=b;x=a;fl=1;}
            if(fl==1 && y>b)
            {
                y=b;
                if(A[x]!=A[a]) x=a;
                else if(x<a) x=a;
            }
        }
        // printf("%d %d\n",x,y);
    }
    vector<int> v;
    if(fl!=-1) {v.push_back(x+1);v.push_back(y+1);}
    return v;
}