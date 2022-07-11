class Solution {
    int getLength(ListNode *n) {
        int res = 0;
        for ( ; n; n = n->next)
            res++;
        return res;
    }
    
    ListNode *advance(ListNode *n, int k) {
        for (int i = 0; i < k; i++)
            n = n->next;
        return n;
    }
    
    pair<ListNode *, ListNode *> slice(ListNode *n) {
        ListNode *a = advance(n, (getLength(n) - 2) / 2);
        ListNode *b = a->next;
        a->next = 0;
        return { n, b };
    }
    
public:
    TreeNode *sortedListToBST(ListNode *n) {
        if (!n)
            return 0;
        
        if (!n->next)
            return new TreeNode(n->val);
        
        auto [a, b] = slice(n);
        return new TreeNode(b->val, sortedListToBST(a), sortedListToBST(b->next));
    }
};