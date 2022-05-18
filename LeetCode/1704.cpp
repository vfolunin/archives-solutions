class Solution {
public:
    bool halvesAreAlike(string s) {
        static const string VOWELS = "aeiou";
        int vowelBalance = 0;
        
        for (int i = 0; i * 2 < s.size(); i++)
            vowelBalance += VOWELS.find(tolower(s[i])) == -1;
        for (int i = s.size() / 2; i < s.size(); i++)
            vowelBalance -= VOWELS.find(tolower(s[i])) == -1;
        
        return !vowelBalance;
    }
};