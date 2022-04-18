class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        ListNode *a = 0, *b = head;
        while (b) {
            ListNode *bNext = b->next;
            b->next = a;
            a = b;
            b = bNext;
        }
        return a;
    }
};