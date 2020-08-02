struct TrieNode
{
    struct TrieNode *children[26];
    int cnt;
    bool isEndOfWord;
};

struct TrieNode *getNode(void)
{
    struct TrieNode *pNode =  new TrieNode;
    pNode->isEndOfWord = false; pNode->cnt=0;
    for (int i=0;i<26;i++) pNode->children[i] = NULL;
    return pNode;
}

void insert(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if(!pCrawl->children[index]) pCrawl->children[index]=getNode();
        pCrawl = pCrawl->children[index];
        pCrawl->cnt++;
    }
    pCrawl->isEndOfWord = true;
}

string search(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;
    string s;
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        pCrawl = pCrawl->children[index];
        s.push_back(key[i]);
        if(pCrawl->cnt==1) return s;
    }
    return s;
}

vector<string> Solution::prefix(vector<string> &A)
{
    struct TrieNode *root = getNode();
    for(int i=0;i<A.size();i++) insert(root,A[i]);
    
    vector<string> v;
    for(int i=0;i<A.size();i++) v.push_back(search(root,A[i]));
    return v;
}