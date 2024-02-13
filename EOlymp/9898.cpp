int sum(ListNode *head) {
    int res = 0;
    for (ListNode *n = head; n; n = n->next)
        res += n->val;
    return res;
}
