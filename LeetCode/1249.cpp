class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<int> stack;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                stack.push_back(i);
            } else if (s[i] == ')' && !stack.empty()) {
                s[stack.back()] = '[';
                s[i] = ']';
                stack.pop_back();
            }
        }
        
        string res;
        for (char c : s) {
            if (isalpha(c))
                res += c;
            else if (c == '[')
                res += '(';
            else if (c == ']')
                res += ')';
        }
        return res;
    }
};