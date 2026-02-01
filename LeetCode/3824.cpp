class Solution {
    bool can(vector<int> &a, int delta) {
        long long count = 0;
        for (int value : a)
            count += (value + delta - 1) / delta;
        return count <= delta * delta;
    }

public:
    int minimumK(vector<int> &a) {
        int l = 0, r = 1;
        while (!can(a, r))
            r *= 2;

        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (can(a, m))
                r = m;
            else
                l = m;
        }
        return r;
    }
};