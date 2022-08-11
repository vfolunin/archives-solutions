class Solution {
    pair<ListNode *, int> advance(ListNode *n, int k) {
        int size = 1;
        for (int i = 0; i < k && n->next; i++) {
            n = n->next;
            size++;
        }
        return { n, size };
    }
    
    ListNode *reverse(ListNode *n) {
        ListNode *a = 0, *b = n;
        while (b) {
            ListNode *bNext = b->next;
            b->next = a;
            a = b;
            b = bNext;
        }
        return a;
    }
    
    ListNode *processGroupAfter(ListNode *n, int size) {
        ListNode *groupHead = n->next;
        auto [groupTail, groupSize]  = advance(groupHead, size - 1);
        ListNode *afterGroup = groupTail->next;
        
        if (groupSize % 2)
            return groupTail;
        
        groupTail->next = 0;
        n->next = reverse(groupHead);
        groupHead->next = afterGroup;
        return groupHead;
    }
    
public:
    ListNode *reverseEvenLengthGroups(ListNode *head) {
        ListNode *n = head;
        for (int size = 2; n->next; size++)
            n = processGroupAfter(n, size);
        return head;
    }
};