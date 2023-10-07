class Solution {
    int getLength(ListNode *head) {
        int res = 1;
        for (ListNode *n = head->next; n != head; n = n->next)
            res++;
        return res;
    }

    ListNode *advance(ListNode *n, int k) {
        for (int i = 0; i < k; i++)
            n = n->next;
        return n;
    }

public:
    vector<ListNode *> splitCircularLinkedList(ListNode *head) {
        int length = getLength(head);
        
        ListNode *aHead = head, *aTail = advance(aHead, (length + 1) / 2 - 1);
        ListNode *bHead = aTail->next, *bTail = advance(bHead, length / 2 - 1);

        aTail->next = aHead;
        bTail->next = bHead;

        return { aHead, bHead };
    }
};