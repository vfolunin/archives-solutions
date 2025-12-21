class Solution {
public:
    long long minCost(string &s, vector<int> &price) {
        vector<long long> cost(26);
        long long totalCost = 0;
        for (int i = 0; i < s.size(); i++) {
            cost[s[i] - 'a'] += price[i];
            totalCost += price[i];
        }
        return totalCost - *max_element(cost.begin(), cost.end());
    }
};