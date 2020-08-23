int Solution::maximalRectangle(vector<vector<int> > &A)
{
    int m=A.size(),n=A[0].size(),dp[m][n]={0};
    
    for(int j=0;j<n;j++)
    {
        int sum=0;
        for(int i=0;i<m;i++)
        {
            sum+=A[i][j];
            if(A[i][j]==0) sum=0;
            dp[i][j]=sum;
        }
    }
    int M=INT_MIN;
    for(int i=0;i<m;i++)
    {
        // Calculate "max area rectangle from histogram" approach (using stack) to
        //find maximum area of square
        stack<int> s;
        int tp,area_with_top,max_area = 0,j=0;
        while(j<n)
        {
            if (s.empty() || dp[i][s.top()]<=dp[i][j])  s.push(j++);
            else
            { 
                tp = s.top(); s.pop();
                // take min of height and base to form a square
                area_with_top = dp[i][tp] * (s.empty() ? j:j-s.top()-1);
                if (max_area < area_with_top) max_area = area_with_top; 
            }
        }
        while(s.empty()==false)
        {
            tp = s.top(); s.pop();
            area_with_top = dp[i][tp] * (s.empty() ? j:j-s.top()-1);
            if (max_area < area_with_top) max_area = area_with_top;
        }
        M=max(M,max_area);
    }
    return M;
}