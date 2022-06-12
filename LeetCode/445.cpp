class Solution {
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
    ListNode *addTwoNumbers(ListNode *a, ListNode *b) {
        a = reverse(a);
        b = reverse(b);
        
        ListNode res = 0, *cur = &res;
        int over = 0;
        
        while (a || b || over) {
            cur = cur->next = new ListNode(0);
            
            int sum = (a ? a->val : 0) + (b ? b->val : 0) + over;
            cur->val = sum % 10;
            over = sum / 10;
            
            if (a)
                a = a->next;
            if (b)
                b = b->next;
        }
        
        return reverse(res.next);
    }
};