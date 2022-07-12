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
    ListNode *reverseBetween(ListNode *head, int l, int r) {
        ListNode *aTail = 0;
        if (l >= 2)
            aTail = advance(head, l - 2);
        
        ListNode *bHead = advance(head, l - 1);
        ListNode *bTail = advance(head, r - 1);

        ListNode *cHead = bTail->next;
        bTail->next = 0;
        
        if (l >= 2)
            aTail->next = reverse(bHead);
        else
            head = reverse(bHead);
        bHead->next = cHead;
        
        return head;
    }
};