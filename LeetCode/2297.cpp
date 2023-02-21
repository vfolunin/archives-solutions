class Solution {
public:
    long long minCost(vector<int> &a, vector<int> &price) {
        vector<long long> cost(a.size(), 1e18);
        cost[0] = 0;

        vector<int> l, r;
        for (int i = 0; i < a.size(); i++) {
            while (!l.empty() && a[l.back()] <= a[i]) {
                cost[i] = min(cost[i], cost[l.back()] + price[i]);
                l.pop_back();
            }
            l.push_back(i);
            
            while (!r.empty() && a[r.back()] > a[i]) {
                cost[i] = min(cost[i], cost[r.back()] + price[i]);
                r.pop_back();
            }
            r.push_back(i);
        }

        return cost.back();
    }
};