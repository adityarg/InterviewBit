vector<vector<int> > Solution::fourSum(vector<int> &A, int B)
{
    vector<vector<int> > v;
    if(A.size()<4) return v;
    
    sort(A.begin(),A.end()); int n=A.size();
    for(int i=0;i<n-3;i++)
    {
        if(i>0 && A[i]==A[i-1]) continue;
        for(int j=i+1;j<n-2;j++)
        {
            if(j>1 && A[j]==A[j-1]) continue;
            {
                int k=j+1,l=n-1;
                while(k<l)
                {
                    if(A[k]+A[l]>B-A[i]-A[j]) l--;
                    else if(A[k]+A[l]<B-A[i]-A[j]) k++;
                    else
                    {
                        vector<int> h;
                        h.push_back(A[i]);h.push_back(A[j]);h.push_back(A[k]);
                        h.push_back(A[l]);v.push_back(h);
                        k++;l--;
                        while(k+1<l-1 && A[k]==A[k+1] && A[l]==A[l-1]) {k++;l--;}
                        k++;l--;
                    }
                }
            }
        }
    }
    return v;
}