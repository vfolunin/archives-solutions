class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {      
        ListNode *l = head, *r = head;
        for (int i = 0; i < n; i++)
            r = r->next;
        
        if (!r)
            return head->next;
        
        while (r->next) {
            l = l->next;
            r = r->next;
        }

        l->next = l->next->next;
        return head;
    }
};