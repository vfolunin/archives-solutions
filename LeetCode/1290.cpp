class Solution {
public:
    int getDecimalValue(ListNode *head) {
        int res = 0;
        for (; head; head = head->next)
            res = res * 2 + head->val;
        return res;
    }
};