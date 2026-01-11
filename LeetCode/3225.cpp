class Solution {
    long long getSum(vector<vector<long long>> &p, int yl, int yr, int x) {
        if (yl > yr)
            return 0;
        return p[yr][x] - (yl ? p[yl - 1][x] : 0);
    }

    long long rec(vector<vector<long long>> &p, int x, int prevH, int isBigger, vector<vector<vector<long long>>> &memo) {
        long long &res = memo[x][prevH][isBigger];
        if (res != -1)
            return res;
        
        if (x == p[0].size())
            return res = 0;

        res = 0;
        for (int h = 0; h <= p.size(); h++) {
            long long prevSum = 0;
            if (x && isBigger)
                prevSum = getSum(p, prevH, h - 1, x - 1);

            res = max(res, prevSum + rec(p, x + 1, h, 0, memo) + getSum(p, h, prevH - 1, x));
            res = max(res, prevSum + rec(p, x + 1, h, 1, memo));
        }
        return res;
    }

public:
    long long maximumScore(vector<vector<int>> &a) {
        vector<vector<long long>> p(a.size(), vector<long long>(a[0].size()));
        for (int y = 0; y < a.size(); y++)
            for (int x = 0; x < a[0].size(); x++)
                p[y][x] = a[y][x] + (y ? p[y - 1][x] : 0);

        vector memo(a.size() + 1, vector(a.size() + 1, vector<long long>(2, -1)));

        return rec(p, 0, 0, 0, memo);
    }
};
