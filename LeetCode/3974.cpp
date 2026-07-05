class Solution {
public:
    long long maxSum(vector<int> &a, int opCount, int factor) {
        sort(a.rbegin(), a.rend());
        long long res = 0;
        for (int i = 0; i < opCount; i++)
            res += 1LL * a[i] * max(factor--, 1);
        return res;
    }
};