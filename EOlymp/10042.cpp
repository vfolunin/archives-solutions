int hasCycle(ListNode *head) {
    if (!head)
        return 0;
    for (ListNode *a = head, *b = head->next; a && b && b->next; a = a->next, b = b->next->next)
        if (a == b)
            return 1;
    return 0;
}
