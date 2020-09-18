/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
map<UndirectedGraphNode*,UndirectedGraphNode*> m;

UndirectedGraphNode * dfs(UndirectedGraphNode* node)
{
    if(node==NULL) return NULL;
    
    UndirectedGraphNode* root=new UndirectedGraphNode(node->label);
    m[node]=root;
    
    auto t=node->neighbors;
    auto &v=root->neighbors;
    
    for(int i=0;i<t.size();i++)
    {
        if(m.find(t[i])==m.end()) v.push_back(dfs(t[i]));
        else v.push_back(m[t[i]]);
    }
    
    return root;
}

UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node)
{
    m.clear();
    return dfs(node);
}