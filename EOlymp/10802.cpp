int DistanceToCycle(ListNode *head) {
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
    
    int res = 0;
    for (ListNode *n = head; n != fast; n = n->next)
        res++;
    return res;
}