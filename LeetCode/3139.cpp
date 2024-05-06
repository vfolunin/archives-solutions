class Solution {
public:
    int minCostToEqualizeArray(vector<int> &a, int price1, int price2) {
        long long minValue = *min_element(a.begin(), a.end());
        long long maxValue = *max_element(a.begin(), a.end());
        long long sum = accumulate(a.begin(), a.end(), 0LL);

        long long res = 1e18;
        for (long long value = maxValue, maxDelta = value - minValue; value <= 2 * maxValue; value++, maxDelta++) {
            long long ops = a.size() * value - sum, ops1 = 0;
            if (2 * maxDelta > ops) {
                ops1 = 2 * maxDelta - ops;
                ops -= ops1;
            }
            res = min({ res, (ops + ops1) * price1, ops / 2 * price2 + (ops % 2 + ops1) * price1 });
        }

        return res % (int)(1e9 + 7);
    }
};