class Solution {
    bool can(vector<int> a, vector<int> b, long long t) {
        long long slots0 = t - t / b[0];
        long long slots1 = t - t / b[1];
        long long slots01 = t - t / b[0] - t / b[1] + t / lcm(b[0], b[1]);
        slots0 -= slots01;
        slots1 -= slots01;

        long long delta = min<long long>(a[0], slots0);
        a[0] -= delta;
        delta = min<long long>(a[0], slots01);
        a[0] -= delta;
        slots01 -= delta;

        delta = min<long long>(a[1], slots1);
        a[1] -= delta;
        delta = min<long long>(a[1], slots01);
        a[1] -= delta;

        return !a[0] && !a[1];
    }

public:
    long long minimumTime(vector<int> &a, vector<int> &b) {
        long long l = 0, r = 1;
        while (!can(a, b, r))
            r *= 2;

        while (l + 1 < r) {
            long long m = l + (r - l) / 2;
            if (can(a, b, m))
                r = m;
            else
                l = m;
        }

        return r;
    }
};