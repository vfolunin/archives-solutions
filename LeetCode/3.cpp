class Solution {
    unordered_map<char, int> count;
    int repeatingCount = 0;

    void inc(char c) {
        count[c]++;
        repeatingCount += count[c] == 2;
    }

    void dec(char c) {
        count[c]--;
        repeatingCount -= count[c] == 1;
    }
    
public:
    int lengthOfLongestSubstring(const string &s) {
        int res = 0;
        
        for (int l = 0, r = 0; r < s.size(); r++) {
            inc(s[r]);
            
            while (repeatingCount) {
                dec(s[l]);
                l++;
            }
            
            res = max(res, r - l + 1);
        }
        
        return res;
    }
};