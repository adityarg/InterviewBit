long long int find_height(vector<int>&A, int h)
{
    long long int s=0;
    for(auto i:A)
        if(h<i) s+= (i-h);
    return s;
}

int Solution::solve(vector<int> &A, int B)
{
    int n=A.size();
    sort(A.begin(),A.end());
    // for(auto i:A) cout<<i<<" ";
    // cout<<endl;
    
    int l=0,h=A[n-1],mid;
    
    while(l<h)
    {
        mid=(l+h)/2;
        long long int y=find_height(A,mid);
        // cout<<l<<" "<<h<<" "<<mid<<" --> "<<y<<endl;
        if(y>B) l=mid+1;
        else if(y<B) h=mid-1;
        else {return mid;}
    }
    // cout<<l<<" ^^ "<<h<<" ^^ "<<mid<<endl;
    
    while(find_height(A,l)<B) l--;
    return l;
}