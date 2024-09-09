class Solution {
    bool can(vector<int> &a, int width, long long dist) {
        long long last = -1e18;
        for (int l : a) {
            long long cur = max<long long>(last + dist, l);
            if (cur > l + width)
                return 0;
            last = cur;
        }
        return 1;
    }

public:
    int maxPossibleScore(vector<int> &a, int width) {
        sort(a.begin(), a.end());

        long long l = 0, r = 1;
        while (can(a, width, r))
            r *= 2;
        
        while (l + 1 < r) {
            long long m = l + (r - l) / 2;
            if (can(a, width, m))
                l = m;
            else
                r = m;
        }

        return l;
    }
};