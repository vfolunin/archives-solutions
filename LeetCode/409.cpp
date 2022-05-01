class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> count;
        for (char c : s)
            count[c]++;
        
        int res = 0, odd = 0;
        for (auto &[c, count] : count) {
            res += count / 2;
            odd |= count % 2;
        }
        
        return res * 2 + odd;
    }
};