int Solution::solve(vector<vector<int> > &A)
{
    if(A.size()==0 && A[0].size()==0) return 0;
    int m=A.size(),n=A[0].size();
    vector<vector<int> > count(m,vector<int>(n));
    // count[i][j] stores value corresponding to the number of consecutive cells having 1
    // as their value and are directly above that cell starting from the given cell itself.
    for(int j=0;j<n;j++)
    {
        int sum=0;
        for(int i=0;i<m;i++)
        {
            sum+=A[i][j];
            if(A[i][j]==0) sum=0;
            count[i][j]=sum;
        }
    }
    
    int M=INT_MIN;
    for(int i=0;i<m;i++)
    {
        // Sort column by i_th row
        sort(count[i].begin(),count[i].end());
        
        // Calculate "max area rectangle from histogram" approach (using stack) to
        //find maximum area of rectangle
        stack<int> s;
        int tp,area_with_top,max_area = 0,j=0;
        while(j<n)
        {
            if (s.empty() || count[i][s.top()]<=count[i][j])  s.push(j++);
            else
            { 
                tp = s.top(); s.pop();
                area_with_top = count[i][tp] * (s.empty() ? j:j-s.top()-1); 
                if (max_area < area_with_top) max_area = area_with_top; 
            }
        }
        while(s.empty()==false)
        {
            tp = s.top(); s.pop();
            area_with_top = count[i][tp] * (s.empty() ? j:j-s.top()-1);
            if (max_area < area_with_top) max_area = area_with_top;
        }
        M=max(M,max_area);
    }
    return M;
}