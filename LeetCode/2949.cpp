class Solution {
    bool isVowel(char c) {
        static const string VOWELS = "aeoiu";
        return VOWELS.find(c) != -1;
    }

public:
    int beautifulSubstrings(string &s, int mod) {
        int vowelCount = 0, consonantCount = 0, res = 0;
        unordered_map<int, unordered_map<int, int>> seen;
        seen[0][0] = 1;

        for (int i = 0; i < s.size(); i++) {
            if (isVowel(s[i]))
                vowelCount++;
            else
                consonantCount++;
            int balance = vowelCount - consonantCount;
            
            for (auto &[prevVowelCount, seenCount] : seen[balance]) {
                int vowels = vowelCount - prevVowelCount;
                if (vowels * vowels % mod == 0)
                    res += seenCount;
            }

            seen[balance][vowelCount % mod]++;
        }

        return res;
    }
};