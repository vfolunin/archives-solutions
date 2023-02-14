class Solution {
    int rec(ListNode *n) {
        if (!n->next || rec(n->next)) {
            int sum = n->val + 1;
            n->val = sum % 10;
            return sum / 10;
        }
        return 0;
    }

public:
    ListNode *plusOne(ListNode *head) {
        if (rec(head))
            return new ListNode(1, head);
        else
            return head;
    }
};