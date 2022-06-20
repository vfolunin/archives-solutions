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
    
    pair<ListNode *, ListNode *> slice(ListNode *n) {
        ListNode *a = advance(n, (getLength(n) - 1) / 2);
        ListNode *b = a->next;
        a->next = 0;
        return { n, b };
    }
    
    ListNode *reverse(ListNode *n) {
        ListNode *a = 0, *b = n;
        while (b) {
            ListNode *bNext = b->next;
            b->next = a;
            a = b;
            b = bNext;
        }
        return a;
    }
    
    int maxSum(ListNode *a, ListNode *b) {
        int res = 0;
        for ( ; a && b; a = a->next, b = b->next)
            res = max(res, a->val + b->val);
        return res;
    }
    
public:
    int pairSum(ListNode *head) {
        auto [a, b] = slice(head);
        return maxSum(a, reverse(b));
    }
};