int Solution::bulbs(vector<int> &A)
{
    int c=0;
    for(auto i:A)
    {
        if((i+c)%2==0) c++;
    }
    return c;
}