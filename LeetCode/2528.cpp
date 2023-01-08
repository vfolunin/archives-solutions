class Solution {
    bool can(vector<int> a, int radius, long long extra, long long level) {
        long long sum = 0;
        int r = 0;
        while (r < a.size() && r <= radius) {
            sum += a[r];
            r++;
        }
        
        if (sum < level) {
            extra -= level - sum;
            a[r - 1] += level - sum;
            sum = level;
        }

        for (int i = 1; i < a.size(); i++) {
            if (r < a.size()) {
                sum += a[r];
                r++;
            }
            if (0 <= i - radius - 1)
                sum -= a[i - radius - 1];

            if (sum < level) {
                extra -= level - sum;
                a[r - 1] += level - sum;
                sum = level;
            }
        }

        return extra >= 0;
    }

public:
    long long maxPower(vector<int> &a, int radius, long long extra) {
        long long l = 0, r = 1e11;
        while (l + 1 < r) {
            long long m = l + (r - l) / 2;
            if (can(a, radius, extra, m))
                l = m;
            else
                r = m;
        }
        return l;
    }
};