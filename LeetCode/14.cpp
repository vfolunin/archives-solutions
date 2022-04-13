class Solution {
public:
    string longestCommonPrefix(vector<string> &words) {
        for (int commonPrefix = 0; 1; commonPrefix++)
            for (string &word : words)
                if (commonPrefix == word.size() || words[0][commonPrefix] != word[commonPrefix])
                    return words[0].substr(0, commonPrefix);
    }
};