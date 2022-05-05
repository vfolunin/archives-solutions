class Solution {
public:
    int countPrefixes(vector<string> &words, string s) {
        int res = 0;
        for (string &word : words)
            res += word.size() <= s.size() && s.substr(0, word.size()) == word;
        return res;
    }
};