int length(ListNode *head) {
    int res = 0;
    for (ListNode *n = head; n; n = n->next)
        res++;
    return res;
}
