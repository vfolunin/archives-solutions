class Solution {
public:
    bool queryString(string &s, int n) {
        unordered_set<int> seen;
        
        for (int from = 0; from < s.size(); from++) {
            int value = 0;
            for (int len = 1; len <= 30 && from + len <= s.size(); len++) {
                value = value * 2 + s[from + len - 1] - '0';
                if (1 <= value && value <= n)
                    seen.insert(value);
            }
        }
        
        return seen.size() == n;
    }
};