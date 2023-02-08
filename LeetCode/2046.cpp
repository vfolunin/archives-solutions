class Solution {
public:
    ListNode *sortLinkedList(ListNode *head) {
        ListNode *resHead = head, *resTail = head, *n = head->next;

        while (n) {
            ListNode *nextN = n->next;

            if (n->val <= 0) {
                n->next = resHead;
                resHead = n;
            } else {
                resTail = resTail->next = n;
            }

            n = nextN;
        }

        resTail->next = 0;
        return resHead;
    }
};