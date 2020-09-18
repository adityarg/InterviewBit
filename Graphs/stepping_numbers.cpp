vector<int> Solution::stepnum(int A, int B)
{
    vector<int> ans;
    if(A <= 0) ans.push_back(0);

    queue<int> q({1, 2, 3, 4, 5, 6, 7, 8, 9});
    
    while(q.front()<=B)
    {
        int i=q.front(); q.pop();
        if(i>=A) ans.push_back(i);
        
        int lastd = i%10;
        if(lastd>0) q.push(i*10+(lastd-1));
        if(lastd<9) q.push(i*10+(lastd+1));
    }
    
    return ans;
}