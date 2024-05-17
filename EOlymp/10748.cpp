ListNode *removeCycle(ListNode *head) {
    ListNode *fast = head, *slow = head;
    do {
        if (!fast || !fast->next || !fast->next->next)
            return head;
        fast = fast->next->next;
        slow = slow->next;
    } while (fast != slow);
    
    fast = head;
    while (fast != slow) {
        fast = fast->next;
        slow = slow->next;
    }
    
    ListNode *n = head;
    while (n->next != fast)
        n = n->next;
    n = n->next;
    while (n->next != fast)
        n = n->next;
    n->next = 0;

    return head;
}