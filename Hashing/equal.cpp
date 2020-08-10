vector<int> Solution::equal(vector<int> &A)
{
    map<int,vector<int> > m; vector<int> ans={INT_MAX,INT_MAX,INT_MAX,INT_MAX};
    int fl=0;
    for(int i=0;i<A.size();i++)
    {
        for(int j=i+1;j<A.size();j++)
        {
            if(m.find(A[i]+A[j])==m.end())
                {m[A[i]+A[j]].push_back(i); m[A[i]+A[j]].push_back(j);}
            else
            {
                int x=m[A[i]+A[j]][0],y=m[A[i]+A[j]][1];
                if(x==i || y==i || y==j || x==j) continue;
                if(x<ans[0] || (x==ans[0]&&y<ans[1]) || (x==ans[0]&&y==ans[1]&&i<ans[2])
                || (x==ans[0]&&y==ans[1]&&i<ans[2]&&j<ans[3]))
                    {
                        // cout<<x<<" "<<y<<" "<<i<<" "<<j;
                        fl=1;ans[0]=x; ans[1]=y; ans[2]=i; ans[3]=j;}
            }
            // cout<<" --> "<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<" "<<ans[3]<<endl;
        }
    }
    if(fl) return ans;
    else return {};
}