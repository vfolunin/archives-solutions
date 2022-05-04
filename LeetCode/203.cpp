class Solution {
public:
    ListNode *removeElements(ListNode *head, int val) {
        while (head && head->val == val)
            head = head->next;
        
        for (ListNode *n = head; n; n = n->next)
            while (n->next && n->next->val == val)
                n->next = n->next->next;
        
        return head;
    }
};