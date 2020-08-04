// A natural way most people would think is to try to maintain the queue size the same
// as the window’s size. Try to break away from this thought and try to think outside
// of the box. Removing redundant elements and storing only elements that need to be
// considered in the queue is the key to achieve the efficient O(n) solution.

vector<int> Solution::slidingMaximum(const vector<int> &A, int B)
{
    vector<int> v;
    if(A.size()<B) return v;
    deque<int> g;
    for(int i=0;i<B;i++)
    {
        while(!g.empty() && A[g.back()]<A[i]) g.pop_back();
        g.push_back(i);
    }
    v.push_back(A[g.front()]);
    for(int i=B;i<A.size();i++)
    {
        while(!g.empty() && A[g.back()]<A[i]) g.pop_back();
        g.push_back(i);
        while(!g.empty() && g.front()<i-(B-1)) g.pop_front();
        v.push_back(A[g.front()]);
    }
    return v;
}