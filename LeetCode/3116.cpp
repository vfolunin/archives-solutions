class Solution {
    bool can(vector<int> &a, int k, long long sum) {
        long long count = 0;
        for (int mask = 1; mask < (1 << a.size()); mask++) {
            int ones = 0, divisor = 1;
            for (int bit = 0; bit < a.size(); bit++) {
                if (mask & (1 << bit)) {
                    ones++;
                    divisor = lcm(divisor, a[bit]);
                }
            }
            count += sum / divisor * (ones % 2 ? 1 : -1);
        }
        return count >= k;
    }

public:
    long long findKthSmallest(vector<int> &a, int k) {
        long long l = 0, r = 1;
        while (!can(a, k, r))
            r *= 2;

        while (l + 1 < r) {
            long long m = l + (r - l) / 2;
            if (can(a, k, m))
                r = m;
            else
                l = m;
        }
        return r;
    }
};