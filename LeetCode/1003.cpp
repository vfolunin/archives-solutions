class Solution {
public:
    bool isValid(string &s) {
        string stack;
        for (char c : s) {
            stack.push_back(c);
            while (stack.size() >= 3 && stack.substr(stack.size() - 3) == "abc")
                for (int i = 0; i < 3; i++)
                    stack.pop_back();
        }
        return stack.empty();
    }
};