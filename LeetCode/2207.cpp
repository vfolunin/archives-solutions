class Solution {
public:
    long long maximumSubsequenceCount(string &text, string &pattern) {
        if (pattern[0] == pattern[1]) {
            long long k = count(text.begin(), text.end(), pattern[0]);
            return k * (k + 1) / 2;
        }
        
        long long res0 = 0, k0 = 1;
        for (int i = 0; i < text.size(); i++) {
            if (text[i] == pattern[0])
                k0++;
            else if (text[i] == pattern[1])
                res0 += k0;
        }
        
        long long res1 = 0, k1 = 1;
        for (int i = text.size() - 1; i >= 0; i--) {
            if (text[i] == pattern[1])
                k1++;
            else if (text[i] == pattern[0])
                res1 += k1;
        }
        
        return max(res0, res1);
    }
};