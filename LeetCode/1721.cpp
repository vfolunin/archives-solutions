class Solution {
    int getLength(ListNode *n) {
        int res = 0;
        for ( ; n; n = n->next)
            res++;
        return res;
    }
    
    ListNode *advance(ListNode *n, int k) {
        for (int i = 0; i < k; i++)
            n = n->next;
        return n;
    }
    
public:
    ListNode *swapNodes(ListNode *head, int k) {
        ListNode *a = advance(head, k - 1);
        ListNode *b = advance(head, getLength(head) - k);
        
        swap(a->val, b->val);
        
        return head;
    }
};