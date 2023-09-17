class Solution {
    vector<int> getOddFactors(int n) {
        map<int, int> factorization;
        for (long long d = 2; d * d <= n; d++) {
            while (n % d == 0) {
                factorization[d]++;
                n /= d;
            }
        }
        if (n != 1)
            factorization[n]++;
        
        vector<int> oddFactors;
        for (auto &[factor, power] : factorization)
            if (power % 2)
                oddFactors.push_back(factor);
        return oddFactors;
    }

public:
    long long maximumSum(vector<int> &a) {
        map<vector<int>, long long> sums;
        for (int i = 0; i < a.size(); i++)
            sums[getOddFactors(i + 1)] += a[i];
        
        long long res = 0;
        for (auto &[_, sum] : sums)
            res = max(res, sum);
        return res;
    }
};