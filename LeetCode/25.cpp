class Solution {    
    ListNode *advance(ListNode *n, int k) {
        for (int i = 0; i < k && n; i++)
            n = n->next;
        return n;
    }
    
    ListNode *reverse(ListNode *n) {
        ListNode *a = 0, *b = n;
        while (b) {
            ListNode *bNext = b->next;
            b->next = a;
            a = b;
            b = bNext;
        }
        return a;
    }
    
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *n = advance(head, k - 1);
        if (!n)
            return head;

        ListNode *tail = reverseKGroup(n->next, k);
        n->next = 0;
        ListNode *res = reverse(head);
        head->next = tail;
        return res;
    }
};