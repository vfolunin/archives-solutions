void PrintReverse(ListNode *n) {
    if (!n)
        return;
    
    PrintReverse(n->next);
    cout << n->val << " ";
}
