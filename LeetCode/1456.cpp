class Solution {
    bool isVowel(char c) {
        static const string VOWELS = "aeiou";
        return VOWELS.find(c) != -1;
    }
    
public:
    int maxVowels(string &s, int k) {
        int cur = 0;
        for (int i = 0; i < k; i++)
            cur += isVowel(s[i]);
        
        int res = cur;
        for (int i = k; i < s.size(); i++) {
            cur += isVowel(s[i]) - isVowel(s[i - k]);
            res = max(res, cur);
        }
        return res;
    }
};