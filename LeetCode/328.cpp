class Solution {
public:
    ListNode *oddEvenList(ListNode *head) {
        if (!head || !head->next)
            return head;
        
        ListNode *a = head, *bHead = head->next, *b = bHead;
        
        while (a->next && a->next->next) {
            a = a->next = a->next->next;
            if (b->next)
                b = b->next = b->next->next;
        }
        
        a->next = bHead;
        
        return head;
    }
};