class Solution {
public:
    void reverseWords(vector<char> &s) {
        for (int l = 0, r = 0; l < s.size(); l = r + 1, r++) {
            while (r < s.size() && s[r] != ' ')
                r++;
            reverse(s.begin() + l, s.begin() + r);
        }
        reverse(s.begin(), s.end());
    }
};