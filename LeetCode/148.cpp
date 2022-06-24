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
    
    ListNode *merge(ListNode *a, ListNode *b) {
        if (!a || !b)
            return a ? a : b;
        if (a->val <= b->val) {
            a->next = merge(a->next, b);
            return a;
        } else {
            b->next = merge(a, b->next);
            return b;
        }
    }
    
public:
    ListNode *sortList(ListNode *head) {
        if (!head || !head->next)
            return head;
        
        auto [a, b] = slice(head);
        return merge(sortList(a), sortList(b));
    }
};