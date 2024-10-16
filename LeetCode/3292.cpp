class Solution {
public:
    vector<int> prefixFunction(const string &s) {
        vector<int> p(s.size());
        for (int i = 1; i < s.size(); i++) {
            int border = p[i - 1];
            while (border > 0 && s[i] != s[border])
                border = p[border - 1];
            p[i] = border + (s[i] == s[border]);
        }
        return p;
    }

    int minValidStrings(vector<string> &words, string &text) {
        vector<int> maxP(text.size() + 1);
        for (const string &word : words) {
            vector<int> p = prefixFunction(word + "#" + text);
            for (int i = 1; i <= text.size(); i++)
                maxP[i] = max(maxP[i], p[word.size() + i]);
        }

        int len = text.size(), res = 0;
        for ( ; len && maxP[len]; len -= maxP[len])
            res++;
        return len ? -1 : res;
    }
};