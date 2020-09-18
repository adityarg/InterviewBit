/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
TreeNode* bst(ListNode* A)
{
    if(A==NULL) return NULL;
    
    ListNode *s=A,*f=A;
    while(s->next!=NULL && f->next!=NULL && f->next->next!=NULL)
    { s=s->next; f=f->next->next;}
    
    TreeNode* root=new TreeNode(s->val);
    if(s!=A)
    {
        ListNode* g=A;
        while(g->next!=s) g=g->next;
        g->next=NULL;
        root->left =bst(A);
    }
    root->right=bst(s->next);
    return root;
}

TreeNode* Solution::sortedListToBST(ListNode* A)
{
    return bst(A);
}