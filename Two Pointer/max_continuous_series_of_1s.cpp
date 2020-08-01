vector<int> Solution::maxone(vector<int> &A, int B)
{
    int i=0,j=0,x=0,y=0,c=0;
    while(j<A.size())
    {
        if(A[j]==1) {j++;}
        else
        {
            if(c<B) {c++;j++;}
            else
            {
                while(A[i]==1) i++;
                i++;j++;
            }
        }
        if(j-1-i>y-x) {x=i;y=j-1;}
    }
    vector<int> v;
    for(int k=x;k<=y;k++) v.push_back(k);
    return v;
}