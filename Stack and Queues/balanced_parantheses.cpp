int Solution::solve(string A)
{
    stack<char> s;
    int i=0;
    while(i<A.size())
    {
        if(A[i]=='(') s.push(A[i]);
        else
        {
            if(s.empty()) return 0;
            else s.pop();
        }
        i++;
    }
    if(s.empty()) return 1;
    return 0;
}