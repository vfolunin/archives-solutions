class Solution {
public:
    bool scoreBalance(string s) {
        int l = 0, r = 0;
        for (char c : s)
            r += c - 'a' + 1;
        
        for (int i = 0; i + 1 < s.size(); i++) {
            l += s[i] - 'a' + 1;
            r -= s[i] - 'a' + 1;
            if (l == r)
                return 1;
        }

        return 0;
    }
};