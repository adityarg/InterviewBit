/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* A, int B)
{
    ListNode* h=A,*P=NULL;
    while(h!=NULL)
    {
        // cout<<h->val<<endl;
        ListNode*curr=h,*prev=NULL,*n,*N=h; int c=0;
        while(c<B)
        {
            n=curr->next;
            curr->next=prev;
            prev=curr; curr=n; c++;
        }
        if(P) {P->next=prev;}
        else {A=prev;}
        N->next=curr;
        if(c!=B || curr==NULL) break;
        
        c=1; P=curr;
        while(c<B) {c++; P=P->next;}
        if(c!=B) break;
        h=P->next;
    }
    return A;
}