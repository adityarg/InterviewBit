int Solution::solve(int A, vector<vector<int> > &B, int C, int D, vector<vector<int> > &E)
{
    vector<vector<pair<int,int> > > adj(A+1);
    for(int i=0;i<B.size();i++)
    {
        // cout<<"aa"<<endl;
        adj[B[i][0]].push_back({B[i][1],B[i][2]});
    }
    // cout<<"bb"<<endl;
    // for(int i=1;i<=A;i++) cout<<adj[i].size()<<endl;
    
    vector<int> d(A+1,INT_MAX); d[C]=0;
    set<pair<int,int> > s;
    s.insert({d[C],C});
    
    while(!s.empty())
    {
        pair<int,int> p=*(s.begin()); s.erase(s.begin());
        int u=p.second;
        
        for(int i=0;i<adj[u].size();i++)
        {
            int v=adj[u][i].first, w=adj[u][i].second;
            if(d[u] + w < d[v])
            {
                if(d[v]!=INT_MAX) s.erase(s.find(make_pair(d[v], v)));
                
                d[v] = d[u]+w;
                s.insert({d[v],v});
            }
        }
    }
    
    // for(int i=1;i<=A;i++) cout<<d[i]<<"\t";
    // cout<<endl;
    
    int ans=d[D];
    for(int i=0;i<E.size();i++)
    {
        vector<int> nd(A+1);
        for(int i=0;i<=A;i++) nd[i]=d[i];
        
        int a,b;
        if(nd[E[i][0]] == nd[E[i][1]] && nd[E[i][0]] ==INT_MAX) continue;
        
        if(nd[E[i][0]] < nd[E[i][1]]) {a=E[i][0]; b=E[i][1];}
        else {a=E[i][1]; b=E[i][0];}
        
        set<pair<int,int> > s;
        if(nd[a]+E[i][2] < nd[b])
        {
            // if(nd[b]!=INT_MAX) s.erase(s.find(make_pair(nd[b],b)));
            // cout<<"aa"<<endl;
            nd[b] = nd[a] + E[i][2];
            s.insert({nd[b],b});
        }
        
        while(!s.empty())
        {
            pair<int,int> p=*(s.begin()); s.erase(s.begin());
            int u=p.second;
            
            for(int j=0;j<adj[u].size();j++)
            {
                int v=adj[u][j].first, w=adj[u][j].second;
                // cout<<"as "<<v<<" "<<w<<" - "<<nd[v]<<"->  ";
                if(nd[u] + w < nd[v])
                {
                    // if(nd[v]!=INT_MAX) s.erase(s.find(make_pair(nd[v],v)));
                    // cout<<"$$ ";
                    nd[v] = nd[u]+w;
                    s.insert({nd[v],v});
                }
                // cout<<nd[v]<<endl;
            }
        }
        // for(int i=1;i<=A;i++) cout<<nd[i]<<"\t";
        // cout<<endl;
        ans=min(ans,nd[D]);
    }
    if(ans==INT_MAX) return -1;
    else return ans;
}