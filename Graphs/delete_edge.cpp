#define ll long long int

ll max_sum,sum;
int md=1000000007;
ll dfs(vector<int> &A, vector<vector<int> > &v,vector<int> &col,int i)
{
    col[i]=1;
    ll h=0;
    for(auto j:v[i])
        if(col[j]==0)
        {
            ll e=dfs(A,v,col,j); h=(h+e)%md;
            if(max_sum < ((sum-e)*e)%md) max_sum = ((sum-e)*e)%md;
        }
    return (h+A[i])%md;
}

int Solution::deleteEdge(vector<int> &A, vector<vector<int> > &B)
{
    sum=0; for(auto i:A) sum+=i;
    
    int n=INT_MIN; for(int i=0;i<B.size();i++) n=max(n,max(B[i][0],B[i][1]));
    
    vector<vector<int> > v(n);
    for(int i=0;i<B.size();i++)
        {v[B[i][0]-1].push_back(B[i][1]-1); v[B[i][1]-1].push_back(B[i][0]-1);}
    
    vector<int> col(n,0);
    max_sum=0;
    ll y=dfs(A,v,col,0);
    return static_cast<int>(max_sum);
}