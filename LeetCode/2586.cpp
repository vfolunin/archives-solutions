class Solution {
    bool check(string &s) {
        static const string VOWELS = "aeiou";
        return VOWELS.find(s.front()) != -1 && VOWELS.find(s.back()) != -1;
    }

public:
    int vowelStrings(vector<string> &words, int l, int r) {
        int res = 0;
        for (int i = l; i <= r; i++)
            res += check(words[i]);
        return res;
    }
};