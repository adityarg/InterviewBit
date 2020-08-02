struct TrieNode
{
    struct TrieNode *children[2];
    bool isEndOfWord;
};

struct TrieNode *getNode(void)
{
    struct TrieNode *pNode=new TrieNode;
    pNode->isEndOfWord=false;
    for (int i=0;i<2;i++) pNode->children[i]=NULL;
    return pNode;
}

void insert(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;
    for (int i=0;i<key.length();i++)
    {
        int index=key[i]-'0';
        if (!pCrawl->children[index]) pCrawl->children[index] = getNode();
        pCrawl = pCrawl->children[index];
    }
    pCrawl->isEndOfWord = true;
}

int Solution::solve(vector<int> &A, vector<int> &B)
{
    vector<string> str;
    for(int i=0;i<B.size();i++)
    {
        string t; int m=B[i],c=32;
        while(c--) {t.push_back('0'+m%2);m=m/2;}
        reverse(t.begin(),t.end());
        str.push_back(t);
    }
    // for(int i=0;i<str.size();i++)
    // {
    //     cout<<str[i];
    //     cout<<endl;
    // }
    // cout<<endl;
    struct TrieNode* root=getNode();
    for(int i=0;i<str.size();i++) insert(root,str[i]);
    
    str.clear();
    for(int i=0;i<A.size();i++)
    {
        string t; int m=A[i],c=32;
        while(c--) {t.push_back('0'+m%2);m=m/2;}
        reverse(t.begin(),t.end());
        str.push_back(t);
    }
    // for(int i=0;i<str.size();i++)
    // {
    //     cout<<str[i];
    //     cout<<endl;
    // }
    // cout<<endl;
    
    int res=0,maxi=INT_MIN;
    for(int i=0;i<str.size();i++)
    {
        struct TrieNode *h=root;
        int j=0; res=0;
        // cout<<i<<endl;
        while(j<32)
        {
            int msb=str[i][j]-'0';
            // cout<<msb<<" "<<j<<" r:"<<res;
            if(h->children[1-msb]) {h=h->children[1-msb]; res=2*res+1;}
            else {h=h->children[msb]; res=2*res;}
            // cout<<" "<<res<<endl;
            j++;
        }
        maxi=max(maxi,res);
        // cout<<res<<" "<<maxi<<endl<<endl;
    }
    return maxi;
}