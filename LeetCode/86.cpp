class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode aHead, *aTail = &aHead;
        ListNode bHead, *bTail = &bHead;
        
        for (ListNode *n = head; n; n = n->next) {
            if (n->val < x)
                aTail = aTail->next = n;
            else
                bTail = bTail->next = n;
        }
        
        aTail->next = bHead.next;
        bTail->next = 0;
        return aHead.next;
    }
};