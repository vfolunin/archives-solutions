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
    
    void zip(ListNode *a, ListNode *b) {
        while (a && b) {
            ListNode *aNext = a->next;
            ListNode *bNext = b->next;
            
            a->next = b;
            b->next = aNext;
            
            a = aNext;            
            b = bNext;
        }
    }
    
public:
    void reorderList(ListNode *head) {
        auto [a, b] = slice(head);
        zip(a, reverse(b));
    }
};