class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        int powerOfTwo = 0;
        for (char c : s)
            powerOfTwo += (bool)isalpha(c);
        
        vector<string> strings;
        for (int mask = 0; mask < (1 << powerOfTwo); mask++) {
            for (int bit = 0, i = 0; bit < powerOfTwo; bit++, i++) {
                while (!isalpha(s[i]))
                    i++;
                s[i] = (mask & (1 << bit)) ? toupper(s[i]) : tolower(s[i]);
            }
            strings.push_back(s);
        }
        return strings;
    }
};