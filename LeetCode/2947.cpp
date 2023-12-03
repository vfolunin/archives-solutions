class Solution {
    bool isVowel(char c) {
        static const string VOWELS = "aeoiu";
        return VOWELS.find(c) != -1;
    }

public:
    int beautifulSubstrings(string &s, int mod) {
        int balance = 0, res = 0;
        unordered_map<int, vector<int>> seen = { { 0, { -1 } } };

        for (int i = 0; i < s.size(); i++) {
            balance += isVowel(s[i]) ? 1 : -1;
            for (int j : seen[balance]) {
                int vowels = (i - j) / 2;
                res += vowels * vowels % mod == 0;
            }
            seen[balance].push_back(i);
        }

        return res;
    }
};