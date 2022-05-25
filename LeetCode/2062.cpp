class Solution {
public:
    int countVowelSubstrings(string s) {
        static const string VOWELS = "aeiou";
        int res = 0;
        
        for (int l = 0; l < s.size(); l++) {
            vector<int> letterCount(5);
            for (int r = l; r < s.size(); r++) {
                if (int pos = VOWELS.find(s[r]); pos != -1)
                    letterCount[pos]++;
                else
                    break;
                res += !count(letterCount.begin(), letterCount.end(), 0);
            }
        }
        
        return res;
    }
};