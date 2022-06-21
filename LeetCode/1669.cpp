class Solution {
public:
    ListNode *mergeInBetween(ListNode *a, int l, int r, ListNode *b) {
        ListNode *n = a;
        for (int i = 0; i < l - 1; i++)
            n = n->next;
        
        ListNode *n2 = n->next;
        for (int i = l; i <= r; i++)
            n2 = n2->next;
        
        n->next = b;
        while (n->next)
            n = n->next;
        
        n->next = n2;
        
        return a;
    }
};