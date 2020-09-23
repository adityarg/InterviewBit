int Solution::seats(string A)
{
    vector<int> p;
    for(int i=0;i<A.size();i++)
        if(A[i]=='x') p.push_back(i);
    
    int m1,m2, r1=0, r2=0;
    if(p.size()%2==0) {m1=(p.size()/2)-1; m2=p.size()/2;}
    else {m1=m2=p.size()/2;}
    
    for(int i=0;i<p.size();i++)
    {
        r1 = (r1+abs(p[m1]-p[i])-abs(i-m1))%10000003;
        r2 = (r2+abs(p[m2]-p[i])-abs(i-m2))%10000003;
    }
    return min(r1,r2);
}