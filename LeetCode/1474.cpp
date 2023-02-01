class Solution {
    ListNode *advance(ListNode *n, int k) {
        for (int i = 0; n && i < k; i++)
            n = n->next;
        return n;
    }

public:
    ListNode *deleteNodes(ListNode *head, int aCount, int bCount) {
        ListNode *a = head;

        while (1) {
            a = advance(a, aCount - 1);
            if (!a)
                break;

            ListNode *b = advance(a, bCount + 1);
            a = a->next = b;
        }

        return head;
    }
};