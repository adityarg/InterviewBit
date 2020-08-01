/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
void print(ListNode* h)
{
    while(h!=NULL) cout<<h->val<<" -> ";
    cout<<endl;
}

ListNode* Solution::partition(ListNode* A, int x)
{
    if(A==NULL || A->next==NULL) return A;
    
    ListNode*h=NULL,*l=NULL,*f=A,*ans=A;
    while(f!=NULL)
    {
        if(f->val<x)
        {
            if(h==NULL && l==NULL) {ans=f;h=f;f=f->next;}
            else if(h!=NULL && h->next==f) {h=f;f=f->next;}
            else
            {
                l->next=f->next;
                if(h!=NULL) {f->next=h->next;h->next=f;h=f;}
                else {f->next=A;ans=f;h=f;}
                // if(h!=NULL) {}
                f=l->next;
            }
        }
        else
        {
            l=f;f=f->next;
        }
        // print(ans);
        // cout<<"^^ "<<f->val<<endl;
    }
    return ans;
}