class Solution {
public:
    int longestValidSubstring(string &s, vector<string> &forbiddenWords) {
        unordered_set<string> forbidden;
        for (string &forbiddenWord : forbiddenWords)
            forbidden.insert(forbiddenWord);

        int len = 0, res = 0;
        for (int l = s.size() - 1; l >= 0; l--) {
            len++;
            for (int r = l; r < l + 10 && r < s.size(); r++) {
                if (forbidden.count(s.substr(l, r - l + 1))) {
                    len = min(len, r - l);
                    break;
                }
            }
            res = max(res, len);
        }
        return res;
    }
};