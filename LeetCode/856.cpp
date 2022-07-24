class Solution {
public:
    int scoreOfParentheses(string &s) {
        vector<int> stack = { 0 };
        
        for (char c : s) {
            if (c == '(') {
                stack.push_back(0);
            } else {
                stack[stack.size() - 2] += stack.back() ? stack.back() * 2 : 1;
                stack.pop_back();
            }
        }
        
        return stack.back();
    }
};