class Solution {
public:
    int minLength(string &s) {
        string stack;

        for (char c : s) {
            if (!stack.empty() && (stack.back() == 'A' || stack.back() == 'C') && stack.back() + 1 == c)
                stack.pop_back();
            else
                stack.push_back(c);
        }
        
        return stack.size();
    }
};