class Solution {
    int getDist(vector<int> &a, vector<int> &b) {
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }

    int rec(int ai, int aSize, int bMask, int bSize, vector<vector<int>> &dist, vector<vector<int>> &memo) {
        int &res = memo[ai][bMask];
        if (res != -1)
            return res;

        if (ai == aSize)
            return res = 0;
        
        res = 1e9;
        for (int bi = 0; bi < bSize; bi++)
            if (!(bMask & (1 << bi)))
                res = min(res, dist[ai][bi] + rec(ai + 1, aSize, bMask | (1 << bi), bSize, dist, memo));
        return res;
    }

public:
    int assignBikes(vector<vector<int>> &a, vector<vector<int>> &b) {
        vector<vector<int>> dist(a.size(), vector<int>(b.size()));
        for (int ai = 0; ai < a.size(); ai++)
            for (int bi = 0; bi < b.size(); bi++)
                dist[ai][bi] = getDist(a[ai], b[bi]);
        
        vector<vector<int>> memo(a.size() + 1, vector<int>(1 << b.size(), -1));
        return rec(0, a.size(), 0, b.size(), dist, memo);
    }
};