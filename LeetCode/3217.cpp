class Solution {
    ListNode *modify(ListNode *n, const unordered_set<int> &values) {
        if (!n)
            return n;

        n->next = modify(n->next, values);
        return values.count(n->val) ? n->next : n;
    }

public:
    ListNode *modifiedList(vector<int> &a, ListNode *head) {
        return modify(head, { a.begin(), a.end() });
    }
};