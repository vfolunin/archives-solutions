class Solution {
    int getLength(ListNode *n) {
        int res = 0;
        for ( ; n; n = n->next)
            res++;
        return res;
    }
    
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head)
            return head;
        
        k %= getLength(head);
        
        ListNode *l = head, *r = head;
        for (int i = 0; i < k; i++)
            r = r->next;

        while (r->next) {
            l = l->next;
            r = r->next;
        }
        
        r->next = head;
        head = l->next;
        l->next = 0;
        return head;
    }
};