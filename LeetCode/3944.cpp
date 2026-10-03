class Solution {
    long long getSum(vector<long long> &p, int l, int r) {
        return p[r] - (l ? p[l - 1] : 0);
    }

    set<pair<long long, int>> getMinCost(vector<int> &count) {
        vector<long long> pCount(count.size() * 3), pSum(count.size() * 3);
        for (int i = 0; i < pCount.size(); i++) {
            int value = i % count.size();
            pCount[i] = count[value] + (i ? pCount[i - 1] : 0);
            pSum[i] = 1LL * i * count[value] + (i ? pSum[i - 1] : 0);
        }

        set<pair<long long, int>> minCost;

        for (int value = 0; value < count.size(); value++) {
            int i = value + count.size();
            int li = i - count.size() / 2;
            int ri = i + (count.size() - 1) / 2;
            long long cost = (getSum(pCount, li, i - 1) - getSum(pCount, i + 1, ri)) * i -
                             (getSum(pSum, li, i - 1) - getSum(pSum, i + 1, ri));

            minCost.insert({ cost, value });
            if (minCost.size() > 2)
                minCost.erase(prev(minCost.end()));
        }

        return minCost;
    }

public:
    long long minOperations(vector<int> &a, int divisor) {
        vector<vector<int>> count(2, vector<int>(divisor));
        for (int i = 0; i < a.size(); i++)
            count[i % 2][a[i] % divisor]++;
        
        vector<set<pair<long long, int>>> minCost(2);
        for (int i = 0; i < minCost.size(); i++)
            minCost[i] = getMinCost(count[i]);
        
        long long res = 1e18;
        for (auto &[cost0, value0] : minCost[0])
            for (auto &[cost1, value1] : minCost[1])
                if (value0 != value1)
                    res = min(res, cost0 + cost1);
        return res;
    }
};