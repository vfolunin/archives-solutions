class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode resHead, *resTail = &resHead;
        
        for (ListNode *n = head; n; ) {
            if (!n->next || n->val != n->next->val) {
                resTail = resTail->next = n;
                n = n->next;
            } else {
                int val = n->val;
                while (n && n->val == val)
                    n = n->next;
            }
        }
        
        resTail->next = 0;
        return resHead.next;
    }
};