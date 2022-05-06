class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>> stack;
        for (char c : s) {
            if (stack.empty() || c != stack.back().first)
                stack.push_back({ c, 1 });
            else
                stack.back().second++;
            if (stack.back().second == k)
                stack.pop_back();
        }
        
        string res;
        for (auto &[c, count] : stack)
            res += string(count, c);
        return res;
    }
};