class Solution {
public:
    ListNode *insertionSortList(ListNode *n) {
        if (!n->next)
            return n;
        
        ListNode *tail = insertionSortList(n->next);
        cout << n->val << endl;
        if (n->val <= tail->val) {
            n->next = tail;
            return n;
        }
        
        ListNode *p = tail;
        while (p->next && p->next->val < n->val)
            p = p->next;
        
        n->next = p->next;
        p->next = n;
        return tail;
    }
};