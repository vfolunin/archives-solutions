class Solution {
    vector<int> zFunction(const string &s) {
        vector<int> z(s.size());

        int blockL = 0, blockR = 0;
        for (int i = 1; i < s.size(); i++) {
            int blockLen = 0;

            if (i <= blockR)
                blockLen = min(z[i - blockL], blockR - i + 1);

            while (i + blockLen <= s.size() && s[i + blockLen] == s[blockLen])
                blockLen++;

            z[i] = blockLen;

            if (blockR < i + blockLen - 1) {
                blockL = i;
                blockR = i + blockLen - 1;
            }
        }

        return z;
    }

public:
    int minStartingIndex(string &text, string &word) {
        vector<int> zl = zFunction(word + "#" + text);
        zl.erase(zl.begin(), zl.begin() + word.size() + 1);

        reverse(text.begin(), text.end());
        reverse(word.begin(), word.end());

        vector<int> zr = zFunction(word + "#" + text);
        zr.erase(zr.begin(), zr.begin() + word.size() + 1);
        reverse(zr.begin(), zr.end());

        for (int l = 0, r = word.size() - 1; r < text.size(); l++, r++)
            if (zl[l] + zr[r] >= word.size() - 1)
                return l;
        return -1;
    }
};