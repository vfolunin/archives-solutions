class Solution {
public:
    ListNode *frequenciesOfElements(ListNode *head) {
        unordered_map<int, int> count;
        for (ListNode *n = head; n; n = n->next)
            count[n->val]++;
        
        ListNode *res = 0;
        for (auto &[_, count] : count) {
            ListNode *newRes = new ListNode(count);
            newRes->next = res;
            res = newRes;
        }
        return res;
    }
};