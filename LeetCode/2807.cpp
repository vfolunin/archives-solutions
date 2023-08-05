class Solution {
public:
    ListNode *insertGreatestCommonDivisors(ListNode *head) {
        for (ListNode *n = head; n->next; n = n->next->next)
            n->next = new ListNode(gcd(n->val, n->next->val), n->next);
        return head;
    }
};