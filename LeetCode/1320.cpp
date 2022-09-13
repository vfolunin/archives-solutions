class Solution {
    int rec(string &s, int i, int a, int b, vector<vector<vector<int>>> &memo) {
        int &res = memo[i][a][b];
        if (res != 1e9)
            return res;

        if (i == s.size() - 1)
            return res = 0;

        int ay = a / 6, ax = a % 6;
        int by = b / 6, bx = b % 6;
        int ny = (s[i + 1] - 'A') / 6, nx = (s[i + 1] - 'A') % 6;

        int aDiff = a == 26 ? 0 : abs(ay - ny) + abs(ax - nx);
        int bDiff = b == 26 ? 0 : abs(by - ny) + abs(bx - nx);

        res = min(res, rec(s, i + 1, s[i + 1] - 'A', b, memo) + aDiff);
        res = min(res, rec(s, i + 1, a, s[i + 1] - 'A', memo) + bDiff);

        return res;
    }

public:
    int minimumDistance(string s) {
        vector<vector<vector<int>>> memo(s.size(), vector<vector<int>>(27, vector<int>(27, 1e9)));
        return rec(s, 0, s[0] - 'A', 26, memo);
    }
};