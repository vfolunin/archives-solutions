class Solution {
    vector<int> getPrimeFactors(int n) {
        vector<int> primeFactors;
        for (int d = 2; d * d <= n; d++) {
            if (n % d == 0) {
                primeFactors.push_back(d);
                while (n % d == 0)
                    n /= d;
            }
        }
        if (n > 1)
            primeFactors.push_back(n);
        return primeFactors;
    }

    int getChangeCount(int value, vector<int> &multipleCount) {
        int changeCount = 0;
        vector<int> primeFactors = getPrimeFactors(value);
        for (int mask = 1; mask < (1 << primeFactors.size()); mask++) {
            int ones = 0, product = 1;
            for (int bit = 0; bit < primeFactors.size(); bit++) {
                if (mask & (1 << bit)) {
                    ones++;
                    product *= primeFactors[bit];
                }
            }
            changeCount += multipleCount[product] * (ones % 2 ? 1 : -1);
        }
        return changeCount;
    }

public:
    int maxScore(vector<int> &a, int limit) {
        vector<int> multipleCount(1e5);
        for (int value : a) {
            vector<int> primeFactors = getPrimeFactors(value);
            for (int mask = 1; mask < (1 << primeFactors.size()); mask++) {
                int product = 1;
                for (int bit = 0; bit < primeFactors.size(); bit++)
                    if (mask & (1 << bit))
                        product *= primeFactors[bit];
                multipleCount[product]++;
            }
        }

        int res = 0;
        for (int value : a)
            res = max(res, value == 1 ? value : value - getChangeCount(value, multipleCount) + 1);
        for (int value = 2; value <= limit; value++)
            res = max(res, value - max(getChangeCount(value, multipleCount), 1));
        return res;
    }
};