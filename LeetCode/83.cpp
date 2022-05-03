class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        for (ListNode *cur = head; cur; cur = cur->next)
            while (cur->next && cur->val == cur->next->val)
                cur->next = cur->next->next;
        return head;
    }
};