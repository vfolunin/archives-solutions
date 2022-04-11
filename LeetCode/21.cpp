class Solution {
public:
    ListNode *mergeTwoLists(ListNode *a, ListNode *b) {
        if (!a || !b)
            return a ? a : b;
        if (a->val < b->val) {
            a->next = mergeTwoLists(a->next, b);
            return a;
        } else {
            b->next = mergeTwoLists(a, b->next);
            return b;
        }
    }
};