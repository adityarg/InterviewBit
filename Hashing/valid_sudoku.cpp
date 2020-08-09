int Solution::isValidSudoku(const vector<string> &A)
{
    int M[10][10];
    for(int i=0;i<A.size();i++)
        for(int j=0;j<A.size();j++)
            if(A[i][j]=='.') M[i+1][j+1]=0;
            else M[i+1][j+1]=A[i][j]-'0';
    // for(int i=1;i<=9;i++)
    // {
    //     for(int j=1;j<=9;j++) printf("%d ",M[i][j]);
    //     printf("\n");
    // }
    
    for(int i=1;i<=9;i++)
    {
        vector<int> ch(10,0);
        for(int j=1;j<=9;j++)
        {
            if(M[i][j]==0) continue;
            if(ch[M[i][j]]>0) {return 0;} else ch[M[i][j]]++;
        }
        vector<int> hh(10,0);
        for(int j=1;j<=9;j++)
        {
            if(M[j][i]==0) continue;
            if(hh[M[j][i]]>0) {return 0;} else hh[M[j][i]]++;
        }
    }
    for(int i=1;i<=9;i=i+3)
        for(int j=1;j<=9;j=j+3)
        {
            vector<int> ch(10,0);
            for(int x=i;x<=i+2;x++)
                for(int y=j;y<=j+2;y++)
                {
                    if(M[x][y]==0) continue;
                    if(ch[M[x][y]]>0) {return 0;} else ch[M[x][y]]++;
                }
        }
    return 1;
}