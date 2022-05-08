class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if (!head || !head->next)
            return head;
        
        ListNode *a = head, *b = a->next, *c = swapPairs(b->next);
        b->next = a;
        a->next = c;
        return b;
    }
};