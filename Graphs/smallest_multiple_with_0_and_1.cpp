string Solution::multiple(int N)
{
    if(N==1) return "1";
    
    vector<int> p(N,-1);// parent state
    vector<int> s(N,-1);// step from parent to current
    
    // BFS //
    int steps[2] = {0,1};
    queue<int> q; q.push(1);
    while(q.front()!=0)
    {
        int curr=q.front(); q.pop();
        
        if(curr==0) break;
        
        for(int step: steps)
        {
            int next = (curr*10+step)%N;
            if(p[next]==-1)
            {
                p[next]=curr;
                s[next]=step;
                q.push(next);
            }
        }
    }
    
    // build reversed string //
    deque<char> number;
    for (int state = 0; state != 1; state = p[state]) number.push_front('0' + s[state]);
    number.push_front('1');
    return string(number.begin(), number.end());
}