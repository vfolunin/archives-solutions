class Solution {
public:
    ListNode *mergeNodes(ListNode *head) {
        ListNode *res = new ListNode(0), *cur = res;
        for (head = head->next; head; head = head->next) {
            if (head->val)
                cur->val += head->val;
            else if (head->next)
                cur = cur->next = new ListNode(0);
        }
        return res;
    }
};