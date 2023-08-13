class Solution {
    pair<ListNode *, int> multiplyBy2(ListNode *head) {
        if (!head)
            return { 0, 0 };
        auto [tail, overflow] = multiplyBy2(head->next);
        int sum = head->val * 2 + overflow;
        return { new ListNode(sum % 10, tail), sum / 10 };
    }

public:
    ListNode *doubleIt(ListNode *head) {
        auto [tail, overflow] = multiplyBy2(head);
        if (overflow)
            return new ListNode(overflow, tail);
        else
            return tail;
    }
};