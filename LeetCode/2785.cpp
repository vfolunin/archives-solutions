class Solution {
public:
    string sortVowels(string &s) {
        const string VOWELS = "aeiou";
        
        string sortedVowels;
        for (char c : s)
            if (VOWELS.find(tolower(c)) != -1)
                sortedVowels += c;        
        sort(sortedVowels.begin(), sortedVowels.end());
        
        string res;
        for (int i = 0, j = 0; i < s.size(); i++) {
            if (VOWELS.find(tolower(s[i])) != -1)
                res += sortedVowels[j++];
            else
                res += s[i];
        }
        return res;
    }
};