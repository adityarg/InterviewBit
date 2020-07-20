vector<string> Solution::fullJustify(vector<string> &A, int B)
{
    vector<string> ans;
    if(A.size()==0) return ans;
    for(int i=0;i<A.size();i++)
    {
        string y;
        int j=i,s=-1;
        while(j<A.size() && s<=B)
        {
            s+=A[j].size()+1;
            j++;
        }
        j--;
        
        if(j==A.size()) j--;
        if(s>B) {s=s-A[j].size()-1;j--;}
        int sp=B-s,k=i+1;
        
        y.append(A[i]);
        while(k<=j)
        {
            if(j!=A.size()-1 && sp%(j-i)!=0) {y.append(" ");sp--;}
            if(j!=A.size()-1) for(int ii=1;ii<=(sp/(j-i));ii++) y.append(" ");
            y.append(" ");y.append(A[k]); k++;
        }
        int m=y.size();
        if(m<B) for(int i=0;i<B-m;i++) y.push_back(' ');
        ans.push_back(y);
        i=j;
    }
    return ans;
}