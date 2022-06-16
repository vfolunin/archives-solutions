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
    
    bool haveCommonStart(ListNode *a, ListNode *b) {
        for ( ; a && b; a = a->next, b = b->next)
            if (a->val != b->val)
                return 0;
        return 1;
    }
    
public:
    bool isPalindrome(ListNode *head) {
        auto [a, b] = slice(head);
        return haveCommonStart(a, reverse(b));
    }
};