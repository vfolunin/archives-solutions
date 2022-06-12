class Solution {
public:
    void deleteNode(ListNode *n) {
        n->val = n->next->val;
        n->next = n->next->next;
    }
};