class Solution {
public:
    bool hasSpecialSubstring(string &s, int targetSize) {
        int cur = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i - 1] == s[i]) {
                cur++;
            } else {
                if (cur == targetSize)
                    return 1;
                cur = 1;
            }
        }
        return cur == targetSize;
    }
};