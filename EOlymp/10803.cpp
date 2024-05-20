ListNode *DeleteFirstElement(ListNode *head, int value) {
    if (head && head->val == value)
        return head->next;
    
    for (ListNode *n = head; n->next; n = n->next) {
        if (n->next->val == value) {
            n->next = n->next->next;
            break;
        }
    }

    return head;
}