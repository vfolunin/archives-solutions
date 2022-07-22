class Solution {
public:
    string reverseParentheses(string &s) {
        vector<string> stack = { "" };
        
        for (char c : s) {
            if (c == '(') {
                stack.emplace_back();
            } else if (c == ')') {
                reverse(stack.back().begin(), stack.back().end());
                stack[stack.size() - 2] += stack.back();
                stack.pop_back();
            } else {
                stack.back() += c;
            }
        }
        
        return stack.back();
    }
};