ListNode *MiddleElement(ListNode *head) {
    int size = 0;
    for (ListNode *n = head; n; n = n->next)
        size++;
    
    ListNode *n = head;
    for (int i = 0; i < (size - 1) / 2; i++)
        n = n->next;
    return n;
}