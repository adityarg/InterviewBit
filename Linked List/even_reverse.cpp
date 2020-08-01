/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* A)
{
    if(A==NULL || A->next==NULL) return A;
    ListNode*H=A,*F=A->next;
    ListNode*h=H,*f=F; int fl=1;
    while(f->next!=NULL && h->next!=NULL)
    {
        if(fl) {h->next=f->next;fl=(fl+1)%2;h=h->next;}
        else {f->next=h->next;fl=(fl+1)%2;f=f->next;}
    }
    h->next=NULL; f->next=NULL;
    // h=H;
    // while(h!=NULL) {cout<<h->val<<" ";h=h->next;}
    // cout<<endl;
    // f=F;
    // while(f!=NULL) {cout<<f->val<<" ";f=f->next;}
    // cout<<endl;
    ListNode* curr=F,*prev=NULL,*n;
    while(curr!=NULL)
    {
        n=curr->next;
        curr->next=prev;
        prev=curr; curr=n;
    }
    F=prev;fl=1;h=H;f=F;
    // while(f!=NULL) {cout<<f->val<<" ";f=f->next;}
    // cout<<endl;
    // cout<<h->val<<" "<<f->val<<endl;
    while(f!=NULL && h!=NULL)
    {
        if(fl%2) {n=h->next;h->next=f;fl++;h=n;}
        else {n=f->next;f->next=h;fl++;f=n;}
        // ListNode* a=A;
        // while(a!=NULL) {cout<<a->val<<" ";a=a->next;}
        // cout<<endl;
    }
    // if(fl%2) h->next=f;
    // else f->next=h;
    return A;
}