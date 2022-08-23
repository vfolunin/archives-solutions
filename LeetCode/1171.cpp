class Solution {
public:
    ListNode *removeZeroSumSublists(ListNode *head) {
        int sum = 0;
        unordered_map<int, ListNode *> seen = { { 0, 0 } };
        vector<ListNode *> stack = { 0 };
        
        for (ListNode *n = head; n; n = n->next) {
            sum += n->val;
            
            if (seen.count(sum)) {
                ListNode *from = seen[sum];
                sum -= n->val;           
                
                while (stack.size() > 1 && stack.back() != from) {
                    seen.erase(sum);
                    sum -= stack.back()->val;
                    stack.pop_back();
                }
            } else {
                seen[sum] = n;
                stack.push_back(n);
            }
        }
        
        if (stack.size() == 1)
            return 0;
        
        for (int i = 1; i + 1 < stack.size(); i++)
            stack[i]->next = stack[i + 1];
        stack.back()->next = 0;
        return stack[1];
    }
};