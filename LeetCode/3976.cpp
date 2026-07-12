class Solution {
public:
    long long maxSubarraySum(vector<int> &a, long long factor) {
        vector<long long> cur = { a[0], a[0] * factor, a[0] / factor, (long long)-1e18 };
        long long res = max({ cur[1], cur[2], cur[3] });

        for (int i = 1; i < a.size(); i++) {
            cur = {
                a[i] + max(cur[0], 0LL),
                a[i] * factor + max({ cur[0], cur[1], 0LL }),
                a[i] / factor + max({ cur[0], cur[2], 0LL }),
                a[i] + max({ cur[1], cur[2], cur[3], 0LL })
            };
            res = max({ res, cur[1], cur[2], cur[3] });
        }

        return res;
    }
};