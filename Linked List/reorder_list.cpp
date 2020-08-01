/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reorderList(ListNode* A)
{
    if(A==NULL || A->next==NULL) return A;
    
    ListNode* f=A,*s=A;
    while(s->next!=NULL && f!=NULL && f->next!=NULL) {s=s->next;f=f->next->next;}
    f=s->next;
    s->next=NULL;
    ListNode*curr=f,*prev=NULL,*n;
    while(curr!=NULL)
    {
        n=curr->next;
        curr->next=prev;
        prev=curr;curr=n;
    }
    f=prev;s=A;
    while(f!=NULL)
    {
        n=f->next;
        f->next=s->next;
        s->next=f;
        f=n;s=s->next->next;
    }
    return A;
}