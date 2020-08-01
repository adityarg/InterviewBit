ListNode* Solution::reverseBetween(ListNode* A, int m, int nn)
{
    ListNode*h=A,*g=A,*f=A;m--;nn--;
    if(m==0) h=NULL;
    else while(--m) h=h->next;
    while(nn--) g=g->next;
    
    ListNode*prev;
    if(h==NULL) prev=A;
    else prev=h->next;
    ListNode*curr=prev->next,*start=prev,*n,*last=g->next;
    
    while(curr!=last)
    {
        n=curr->next;
        curr->next=prev;
        prev=curr;
        curr=n;
    }
    if(h==NULL)
    {
        A=prev;
        start->next=last;
    }
    else
    {
        h->next=prev;
        start->next=last;
    }
    return A;
}