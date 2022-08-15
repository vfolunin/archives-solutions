class Solution {
public:
    int longestBeautifulSubstring(string &s) {
        const string VOWELS = "aeiou";
        int last = -1, row = 0, res = 0;
        
        for (char c : s) {
            int i = VOWELS.find(c);
            
            if (last == i || last == i - 1) {
                row++;
                last = i;
            } else if (!i) {
                row = 1;
                last = i;
            } else {
                row = 0;
                last = -1;
            }
            
            if (last == VOWELS.size() - 1)
                res = max(res, row);
        }
        
        return res;
    }
};