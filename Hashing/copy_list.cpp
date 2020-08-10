/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode* Solution::copyRandomList(RandomListNode* head)
{
    // orignal node as key, new node as value
    unordered_map<RandomListNode*,RandomListNode*> mp;
    RandomListNode *curr = head, *clone;
    
    //first set the node data
    while(curr)
    {
        RandomListNode *t = new RandomListNode(curr->label);
        mp[curr] = t;
        curr = curr->next;
    }
    // then set the next and random pointers
    curr = head;
    while(curr)
    {
        clone = mp[curr];
        clone->next = mp[curr->next];
        clone->random = mp[curr->random];
        curr = curr->next;
    }
    return mp[head];
}