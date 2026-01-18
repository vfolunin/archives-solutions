class Solution {
    bool isVowel(char c) {
        static string vowels = "aeiou";
        return vowels.find(c) != -1;
    }

public:
    int vowelConsonantScore(string &s) {
        int vowelCount = 0, consonantCount = 0;
        for (char c : s) {
            if (isalpha(c)) {
                if (isVowel(c))
                    vowelCount++;
                else
                    consonantCount++;
            }
        }
        return consonantCount ? vowelCount / consonantCount : 0;
    }
};