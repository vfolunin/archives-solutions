int length(ListNode *n) {
    int res = 0;
    while (n) {
        res++;
        n = n->next;
    }
    return res;
}

ListNode *intersection(ListNode *a, ListNode *b) {
    int an = length(a), bn = length(b);
    while (an > bn) {
        a = a->next;
        an--;
    }
    while (bn > an) {
        b = b->next;
        bn--;
    }        
    while (a != b) {
        a = a->next;
        b = b->next;
    }
    return a;
}