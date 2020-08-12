long long int trav(int A,map<int,int> &m)
{
    long long int c=0;
    for(int i=0;i<=A-2;i=i+2)
    {
        long long int c1,c2;
        if(m.find(i)!=m.end()) c1=m[i];
        else {c1=trav(i,m); m[i]=c1;}
        if(m.find(A-i-2)!=m.end()) c2=m[A-i-2];
        else {c2=trav(A-i-2,m); m[A-i-2]=c2;}
        c1 = (c1*c2)%1000000007;
        c = (c+c1)%1000000007;
    }
    return c;
}

int Solution::chordCnt(int A)
{
    map<int,int> m;
    m[0]=1; m[2]=1; m[4]=2;
    long long int c=trav(A*2,m);
    return (int)c;
}