class Solution {
    int rec(int i, int size, int last, int mask) {
        if (i == size)
            return 1;
        
        static const vector<vector<int>> MID = {
            { 10, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
            { 10, 10, 0, 2, 0, 0, 0, 4, 0, 5 },
            { 10, 0, 10, 0, 0, 0, 0, 0, 5, 0 },
            { 10, 2, 0, 10, 0, 0, 0, 5, 0, 6 },
            { 10, 0, 0, 0, 10, 0, 5, 0, 0, 0 },
            { 10, 0, 0, 0, 0, 10, 0, 0, 0, 0 },
            { 10, 0, 0, 0, 5, 0, 10, 0, 0, 0 },
            { 10, 4, 0, 5, 0, 0, 0, 10, 0, 8 },
            { 10, 0, 5, 0, 0, 0, 0, 0, 10, 0 },
            { 10, 5, 0, 6, 0, 0, 0, 8, 0, 10 },
        };

        int ways = 0;
        for (int next = 1; next <= 9; next++)
            if (!(mask & (1 << next)) && (mask & (1 << MID[last][next])))
                ways += rec(i + 1, size, next, mask | (1 << next));
        return ways;
    }

public:
    int numberOfPatterns(int l, int r) {
        int ways = 0;
        for (int size = l; size <= r; size++)
            ways += rec(0, size, 0, 1);
        return ways;
    }
};