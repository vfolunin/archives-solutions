class Solution {
    bool isVowel(char c) {
        static const string VOWELS = "aeiou";
        return VOWELS.find(tolower(c)) != -1;
    }

    bool isConsonant(char c) {
        return isalpha(c) && !isVowel(c);
    }

public:
    bool isValid(string &s) {
        if (s.size() < 3)
            return 0;
        
        bool hasVowel = 0, hasConsonant = 0;
        for (char c : s) {
            if (!isalnum(c))
                return 0;
            hasVowel |= isVowel(c);
            hasConsonant |= isConsonant(c);
        }

        return hasVowel && hasConsonant;
    }
};