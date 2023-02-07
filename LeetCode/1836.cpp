class Solution {
public:
    ListNode *deleteDuplicatesUnsorted(ListNode *head) {
        unordered_map<int, int> count;
        for (ListNode *n = head; n; n = n->next)
            count[n->val]++;
        
        ListNode resHead, *resN = &resHead;
        for (ListNode *n = head; n; n = n->next)
            if (count[n->val] == 1)
                resN = resN->next = n;
        resN->next = 0;
        return resHead.next;
    }
};