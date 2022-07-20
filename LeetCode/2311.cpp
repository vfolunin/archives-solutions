class Solution {
    bool can(string &s, int k, int width) {
        long long val = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0' || i + width == s.size()) {
                width--;
                val = val * 2 + s[i] - '0';
                if (val > k)
                    return 0;
            }
        }
        return 1;
    }
    
public:
    int longestSubsequence(string s, int k) {
        int l = 0, r = s.size() + 1;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (can(s, k, m))
                l = m;
            else
                r = m;
        }
        return l;
    }
};