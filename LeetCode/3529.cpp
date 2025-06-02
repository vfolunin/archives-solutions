class Solution {
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

    vector<int> kmp(const string &text, const string &pattern) {
        vector<int> p = prefixFunction(pattern + "#" + text), res;
        for (int i = 2 * pattern.size(); i < p.size(); i++)
            if (p[i] == pattern.size())
                res.push_back(i - 2 * pattern.size());
        return res;
    }

    bool check(vector<int> &from, int index, int limit) {
        auto it = upper_bound(from.begin(), from.end(), index);
        return it != from.begin() && index - *prev(it) < limit;
    }

public:
    int countCells(vector<vector<char>> &a, string &pattern) {
        int h = a.size(), w = a[0].size();

        string text;
        for (int y = 0; y < h; y++)
            for (int x = 0; x < w; x++)
                text += a[y][x];
        vector<int> fromYX = kmp(text, pattern);

        text.clear();
        for (int x = 0; x < w; x++)
            for (int y = 0; y < h; y++)
                text += a[y][x];
        vector<int> fromXY = kmp(text, pattern);

        int res = 0;
        for (int y = 0; y < h; y++)
            for (int x = 0; x < w; x++)
                res += check(fromYX, y * w + x, pattern.size()) && check(fromXY, x * h + y, pattern.size());
        return res;
    }
};