class Solution {
    long long getCost(vector<int> &a, vector<int> &cost, int target) {
        long long res = 0;
        for (int i = 0; i < a.size(); i++)
            res += 1LL * abs(a[i] - target) * cost[i];
        return res;
    }
    
public:
    long long minCost(vector<int> &a, vector<int> &cost) {
        vector<int> values = a;
        sort(values.begin(), values.end());
        values.erase(unique(values.begin(), values.end()), values.end());
        
        int l = 0, r = values.size() - 1;
        while (l + 10 < r) {
            int m1 = l + (r - l) / 3;
            int m2 = r - (r - l) / 3;
            if (getCost(a, cost, values[l]) < getCost(a, cost, values[r]))
                r = m2;
            else
                l = m1;
        }
        
        long long res = 1e18;
        for (int i = l; i <= r; i++)
            res = min(res, getCost(a, cost, values[i]));
        return res;
    }
};