struct TrieNode
{
    struct TrieNode *children[26];
    bool isEndOfWord;
};

struct TrieNode *getNode(void)
{
    struct TrieNode *pNode = new TrieNode;
    pNode->isEndOfWord = false;
    for (int i=0;i<26;i++) pNode->children[i]=NULL;
    return pNode;
}

void insert(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();

        pCrawl = pCrawl->children[index];
    }
    pCrawl->isEndOfWord = true;
}

bool search(struct TrieNode *root, string key) 
{ 
    struct TrieNode *pCrawl = root;
    
    for(int i = 0; i<key.length();i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index]) return false;

        pCrawl = pCrawl->children[index];
    }

    return (pCrawl != NULL && pCrawl->isEndOfWord);
}

bool comp(pair<int,int>&a,pair<int,int>&b)
{
    if(a.first==b.first) return a.second<b.second;
    return a.first>b.first;
}

vector<int> Solution::solve(string A, vector<string> &B)
{
    struct TrieNode *root = getNode();
    int i=0,j=0;
    while(j<A.size())
    {
        if(j==A.size()-1 || A[j]=='_')
        {
            string s;
            if(j!=A.size()-1) s=A.substr(i,j-i);
            else s=A.substr(i,j-i+1);
            insert(root,s);
            i=j+1;
        }
        j++;
    }
    vector<pair<int,int> > v;
    for(int i=0;i<B.size();i++) v.push_back(make_pair(0,i));
    
    for(int k=0;k<B.size();k++)
    {
        int i=0,j=0;
        while(j<B[k].size())
        {
            if(B[k][j]=='_')
            {
                string s;
                if(B[k][j]=='_')
                {s=B[k].substr(i,j-i);if(search(root,s)) v[k].first++;}
                
                i=j+1;
            }
            j++;
        }
        string s;s=B[k].substr(i,j-i); if(search(root,s)) v[k].first++;
    }
    sort(v.begin(),v.end(), comp);
    vector<int> t;
    for(int i=0;i<B.size();i++) t.push_back(v[i].second);
    return t;
}