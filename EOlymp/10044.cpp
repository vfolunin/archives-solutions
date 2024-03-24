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