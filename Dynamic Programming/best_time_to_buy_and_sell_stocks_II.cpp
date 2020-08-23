// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/solution/

int Solution::maxProfit(const vector<int> &A)
{
    int n=A.size(), maxprofit = 0;
    for (int i=1;i<n;i++)
    {
        if (A[i] > A[i-1]) maxprofit+= A[i]-A[i-1];
    }
    return maxprofit;
}