class Solution {
    int digitSum(int n) {
        int sum = 0;
        while (n) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

public:
    int countArrays(vector<int> &sums) {
        vector<vector<int>> sumValues(51);
        for (int value = 0; value <= 5000; value++)
            sumValues[digitSum(value)].push_back(value);
        
        const long long MOD = 1e9 + 7;
        vector<long long> ways(sumValues[sums[0]].size());
        iota(ways.begin(), ways.end(), 1);

        for (int i = 1; i < sums.size(); i++) {
            vector<long long> nextWays(sumValues[sums[i]].size());
            for (int pj = 0, nj = 0; nj < nextWays.size(); nj++) {
                while (pj + 1 < ways.size() && sumValues[sums[i - 1]][pj + 1] <= sumValues[sums[i]][nj])
                    pj++;

                if (pj < ways.size() && sumValues[sums[i - 1]][pj] <= sumValues[sums[i]][nj])
                    nextWays[nj] = ways[pj];
            }

            for (int j = 1; j < nextWays.size(); j++)
                nextWays[j] = (nextWays[j] + nextWays[j - 1]) % MOD;
            ways.swap(nextWays);
        }

        return ways.empty() ? 0 : ways.back();
    }
};