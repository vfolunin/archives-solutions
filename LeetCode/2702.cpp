class Solution {
    bool can(vector<int> &a, int x, int y, int ops) {
        long long xOps = 0;
        for (int value : a)
            xOps += (max(value - ops * y, 0) + x - 1) / x;
        return xOps <= ops;
    }

public:
    int minOperations(vector<int> &a, int x, int y) {
        x -= y;

        int l = -1, r = 1;
        while (!can(a, x, y, r))
            r *= 2;
        
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (can(a, x, y, m))
                r = m;
            else
                l = m;
        }

        return r;
    }
};