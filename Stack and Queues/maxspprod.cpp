int Solution::maxSpecialProduct(vector<int> &A)
{
    int n=A.size();
    long long int left[n],right[n],stack[n+10];
    int top=0;
    
    for(int i=0;i<n;i++)
    {
        if(top==0) {stack[top]=i;top++;left[i]=0;}
        else
        {
            int j=stack[top-1];
            while(top>0 && A[j]<=A[i])
            {
                top--;
                j=stack[top-1];
            }
            if(top==0) left[i]=0;
            else left[i]=stack[top-1];
            stack[top]=i;
            top++;
        }
    }
    top=0;
    for(int i=n-1;i>=0;i--)
    {
        if(top==0) {stack[top]=i;top++;right[i]=0;}
        else
        {
            int j=stack[top-1];
            while(top>0 && A[j]<=A[i])
            {
                top--;
                j=stack[top-1];
            }
            if(top==0) right[i]=0;
            else right[i]=stack[top-1];
            stack[top]=i;
            top++;
        }
    }

    long long int ans[n];
    for(int i=0;i<n;i++) ans[i]=left[i]*right[i];
    sort(ans,ans+n);
    return ans[n-1]%1000000007;
}