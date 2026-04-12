class Solution {
public:
    int maxValue(vector<int> &ones, vector<int> &zeros) {
        vector<int> order(ones.size());
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int l, int r) {
            return string(ones[l], '1') + string(zeros[l], '0') + string(ones[r], '1') + string(zeros[r], '0') >
                   string(ones[r], '1') + string(zeros[r], '0') + string(ones[l], '1') + string(zeros[l], '0');
        });

        const long long MOD = 1e9 + 7;
        long long res = 0;
        for (int i : order) {
            for (int j = 0; j < ones[i]; j++)
                res = (res * 2 + 1) % MOD;
            for (int j = 0; j < zeros[i]; j++)
                res = res * 2 % MOD;
        }
        return res;
    }
};