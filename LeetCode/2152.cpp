class Solution {
    bool collinear(vector<int> &a, vector<int> &b, vector<int> &c) {
        return (a[0] - b[0]) * (a[1] - c[1]) == (a[0] - c[0]) * (a[1] - b[1]);
    }

    int rec(vector<vector<int>> &points, int mask, vector<int> &memo) {
        int &res = memo[mask];
        if (res != -1)
            return res;
        
        if (!mask)
            return res = 0;
        if (!(mask & (mask - 1)))
            return res = 1;
        
        res = 1e9;
        for (int ai = 0; ai < points.size(); ai++) {
            if (!(mask & (1 << ai)))
                continue;
            
            for (int bi = ai + 1; bi < points.size(); bi++) {
                if (!(mask & (1 << bi)))
                    continue;

                int nextMask = mask;
                for (int ci = 0; ci < points.size(); ci++)
                    if (collinear(points[ai], points[bi], points[ci]))
                        nextMask &= ~(1 << ci);

                res = min(res, 1 + rec(points, nextMask, memo));
            }
        }
        return res;
    }

public:
    int minimumLines(vector<vector<int>> &points) {
        vector<int> memo(1 << points.size(), -1);
        return rec(points, (1 << points.size()) - 1, memo);
    }
};