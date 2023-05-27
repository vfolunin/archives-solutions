class Solution {
public:
    int minExtraChar(string &s, vector<string> &words) {
        sort(words.begin(), words.end());
        
        vector<int> res(s.size() + 1);
        for (int len = 1; len <= s.size(); len++) {
            res[len] = res[len - 1] + 1;
            for (int wordLen = 1; wordLen <= len; wordLen++) {
                string word = s.substr(len - wordLen, wordLen);
                if (binary_search(words.begin(), words.end(), word))
                    res[len] = min(res[len], res[len - wordLen]);
            }
        }
        return res[s.size()];
    }
};