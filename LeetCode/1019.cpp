class Solution {
public:
    vector<int> nextLargerNodes(ListNode *n) {
        vector<int> res, stack;
        
        for (int i = 0; n; i++, n = n->next) {
            while (!stack.empty() && res[stack.back()] < n->val) {
                res[stack.back()] = n->val;
                stack.pop_back();
            }
            res.push_back(n->val);
            stack.push_back(i);
        }
        
        while (!stack.empty()) {
            res[stack.back()] = 0;
            stack.pop_back();
        }
        
        return res;
    }
};