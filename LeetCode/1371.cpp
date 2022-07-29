class Solution {
public:
    int findTheLongestSubstring(string s) {
        const string VOWELS = "aeiou";
        
        vector<int> seen(1 << VOWELS.size(), -2);
        seen[0] = -1;
        int res = 0;
        
        for (int i = 0, mask = 0; i < s.size(); i++) {
            if (int bit = VOWELS.find(s[i]); bit != -1)
                mask ^= 1 << bit;
            
            if (seen[mask] == -2)
                seen[mask] = i;
            else
                res = max(res, i - seen[mask]);
        }
        
        return res;
    }
};