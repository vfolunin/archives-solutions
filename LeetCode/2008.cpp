class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>> &rides) {
        sort(rides.begin(), rides.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });
        
        vector<long long> profit(n + 1);
        
        for (int i = 1, ri = 0; i <= n; i++) {
            profit[i] = profit[i - 1];
            for ( ; ri < rides.size() && rides[ri][1] == i; ri++)
                profit[i] = max(profit[i], profit[rides[ri][0]] + rides[ri][1] - rides[ri][0] + rides[ri][2]);
        }
        
        return profit.back();
    }
};