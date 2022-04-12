class Solution {
    char complement(char c) {
        static const string BRACKETS = "()[]{}";
        return BRACKETS[BRACKETS.find(c) ^ 1];
    }
    
public:
    bool isValid(const string &s) {
        string stack;
        for (char c : s) {
            static const string OPEN = "([{";
            if (OPEN.find(c) != -1)
                stack.push_back(c);
            else if (!stack.empty() && stack.back() == complement(c))
                stack.pop_back();
            else
                return false;
        }
        return stack.empty();
    }
};