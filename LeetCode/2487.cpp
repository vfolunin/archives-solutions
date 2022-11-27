class Solution {
public:
    ListNode *removeNodes(ListNode *head) {
        vector<ListNode *> stack;
        for (ListNode *n = head; n; n = n->next) {
            while (!stack.empty() && stack.back()->val < n->val)
                stack.pop_back();
            stack.push_back(n);
        }
        
        for (int i = 0; i + 1 < stack.size(); i++)
            stack[i]->next = stack[i + 1];
        stack.back()->next = 0;
        return stack[0];
    }
};