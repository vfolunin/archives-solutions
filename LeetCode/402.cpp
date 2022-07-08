class Solution {
public:
    string removeKdigits(string &s, int k) {
        string stack;
        for (char c : s) {
            while (!stack.empty() && stack.back() > c && k) {
                stack.pop_back();
                k--;
            }
            stack.push_back(c);
        }
        
        stack = stack.substr(0, stack.size() - k);
        if (stack.empty())
            stack.push_back('0');
        
        reverse(stack.begin(), stack.end());
        while (stack.size() > 1 && stack.back() == '0')
            stack.pop_back();
        reverse(stack.begin(), stack.end());
        
        return stack;
    }
};