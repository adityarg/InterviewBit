int max_depth;
int depth(vector<vector<int>> &v, vector<int> &vis, int root)
{
    vis[root]=1;
    int d1=0,d2=0;
    for(auto i:v[root])
        if(vis[i]==0)
        {
            int d=1+depth(v,vis,i);
            if(d1<d) {d2=d1;d1=d;}
            else if(d2<d) d2=d;
        }
    max_depth=max(max_depth,d1+d2);
    return d1;
}

int Solution::solve(vector<int> &A)
{
    int root;
    for(int i=0;i<A.size();i++)
        if(A[i]==-1) root=i;
    
    vector<vector<int>> v(A.size());
    for(int i=0;i<A.size();i++)
        if(A[i]!=-1) {v[i].push_back(A[i]); v[A[i]].push_back(i);}
    
    vector<int> vis(A.size(),0);
    
    max_depth=INT_MIN;
    int u=depth(v,vis,root);
    
    return max_depth;
}