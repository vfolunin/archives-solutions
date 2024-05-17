int CycleLength(ListNode *head) {
    ListNode *fast = head, *slow = head;
    do {
        if (!fast || !fast->next || !fast->next->next)
            return -1;
        fast = fast->next->next;
        slow = slow->next;
    } while (fast != slow);
    
    fast = head;
    while (fast != slow) {
        fast = fast->next;
        slow = slow->next;
    }
    
    int res = 1;
    for (ListNode *n = fast; n->next != fast; n = n->next)
        res++;
    return res;
}