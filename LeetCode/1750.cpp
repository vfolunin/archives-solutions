class Solution {
public:
    int minimumLength(string &s) {
        int l = 0, r = s.size() - 1;
        
        while (l < r && s[l] == s[r]) {
            do {
                l++;
            } while (l < s.size() && s[l] == s[l - 1]);
            
            do {
                r--;
            } while (r >= 0 && s[r] == s[r + 1]);
        }
        
        return max(r - l + 1, 0);
    }
};