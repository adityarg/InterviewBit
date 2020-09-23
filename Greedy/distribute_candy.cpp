// int Solution::candy(vector<int> &A)
// {
//     int n=A.size();
    
//     map<int,vector<int> > m;
//     for(int i=0;i<n;i++)
//     {
//         if(m.find(A[i])==m.end()) m.insert({A[i],{i}});
//         else m[A[i]].push_back(i);
//     }
    
//     vector<int> v(n,0);
    
//     for(auto t=m.begin();t!=m.end();t++)
//     {
//         for(int j=0;j< t->second.size();j++)
//         {
//             int y=t->second[j];
//             if(y>0 && y<n-1) v[y]=max(v[y-1]+1,v[y+1]+1);
//             else if(y>0) v[y]=v[y-1]+1;
//             else v[y]=v[y+1]+1;
//         }
//     }
//     int sum=0;
//     for(int i=0;i<n;i++) sum+=v[i];
//     return sum;
// }

int Solution::candy(vector<int> &A)
{
    vector<int> arr(A.size(),1);
    
    for(int i=A.size()-2;i>=0;i--)
    {
        if(i!=A.size()-1&&A[i]>A[i+1])
        arr[i]=arr[i+1]+1;
    }
    for(int i=1;i<A.size();i++)
    {
        if(i!=0&&A[i]>A[i-1])
        arr[i]=max(arr[i-1]+1,arr[i]);
    }
    
    int count=0;
    for(int i=0;i<A.size();i++) count+=arr[i];
    return count;
}