class Solution {
    map<int, int> factorize(long long n) {
        map<int, int> factorization;

        for (long long d = 2; d * d <= n; d++) {
            while (n % d == 0) {
                factorization[d]++;
                n /= d;
            }
        }
        if (n != 1)
            factorization[n]++;

        return factorization;
    }

public:
    int countSequences(vector<int> &a, long long target) {
        map<int, int> targetFactors = factorize(target);

        vector<map<int, int>> valueFactors;
        for (int value : a)
            valueFactors.push_back(factorize(value));

        int leftHalfSize = valueFactors.size() / 2;
        int maxMask = 1;
        for (int i = 0; i < leftHalfSize; i++)
            maxMask *= 3;

        map<map<int, int>, int> leftHalfFactors;
        for (int mask = 0; mask < maxMask; mask++) {
            map<int, int> factors;

            for (int i = 0, maskValue = mask; i < leftHalfSize; i++, maskValue /= 3) {
                for (auto &[factor, delta] : valueFactors[i]) {
                    if (maskValue % 3 == 1)
                        factors[factor] += delta;
                    else if (maskValue % 3 == 2)
                        factors[factor] -= delta;
                }
            }

            for (auto it = factors.begin(); it != factors.end(); ) {
                if (it->second)
                    it++;
                else
                    it = factors.erase(it);
            }

            leftHalfFactors[factors]++;
        }

        maxMask = 1;
        for (int i = 0; i < valueFactors.size() - leftHalfSize; i++)
            maxMask *= 3;

        int res = 0;
        for (int mask = 0; mask < maxMask; mask++) {
            map<int, int> factors;

            for (int i = leftHalfSize, maskValue = mask; i < valueFactors.size(); i++, maskValue /= 3) {
                for (auto &[factor, delta] : valueFactors[i]) {
                    if (maskValue % 3 == 1)
                        factors[factor] += delta;
                    else if (maskValue % 3 == 2)
                        factors[factor] -= delta;
                }
            }

            map<int, int> needFactors = targetFactors;
            for (auto &[factor, delta] : factors)
                needFactors[factor] -= delta;
            for (auto it = needFactors.begin(); it != needFactors.end(); ) {
                if (it->second)
                    it++;
                else
                    it = needFactors.erase(it);
            }

            if (auto it = leftHalfFactors.find(needFactors); it != leftHalfFactors.end())
                res += it->second;
        }

        return res;
    }
};