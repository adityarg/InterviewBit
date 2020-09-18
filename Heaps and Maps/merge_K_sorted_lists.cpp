/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class compare{
    public:
        bool operator()(ListNode *l1,ListNode *l2){
            return l1->val > l2->val;
        }
};

ListNode* Solution::mergeKLists(vector<ListNode*> &A)
{
    priority_queue<ListNode*,vector<ListNode*>,compare> g;
    for(int i=0;i<A.size();i++)
        if(A[i]) g.push(A[i]);
    
    ListNode* ans=new ListNode(0),*t=ans;
    while(!g.empty())
    {
        t->next=g.top(); g.pop();
        t=t->next;
        
        if(t->next) g.push(t->next);
    }
    
    return ans->next;
}