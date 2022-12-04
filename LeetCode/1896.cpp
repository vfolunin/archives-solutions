class Solution {
public:
    int minOperationsToFlip(string &s) {
        vector<vector<int>> stack(1, vector<int>(3));
        
        for (char c : s) {
            if (c == '(') {
                stack.push_back(vector<int>(3));
            } else if (c == '&' || c == '|') {
                stack.back()[2] = c;
            } else {
                int cost0, cost1;
                if (isdigit(c)) {
                    cost0 = c != '0';
                    cost1 = c != '1';
                } else {
                    cost0 = stack.back()[0];
                    cost1 = stack.back()[1];
                    stack.pop_back();
                }
                
                if (stack.back()[2] == '&') {
                    cost0 = min(stack.back()[0], cost0);
                    cost1 = min(stack.back()[1] + cost1, min(stack.back()[1], cost1) + 1);
                } else if (stack.back()[2] == '|') {
                    cost0 = min(stack.back()[0] + cost0, min(stack.back()[0], cost0) + 1);
                    cost1 = min(stack.back()[1], cost1);
                }
                stack.back() = { cost0, cost1, 0 };
            }
        }
        
        return max(stack[0][0], stack[0][1]);
    }
};