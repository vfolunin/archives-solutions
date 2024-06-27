class Solution {
public:
    long long maximumTotalCost(vector<int> &a) {
        vector<long long> res(a.size(), -1e18);
        for (int i = 0; i < a.size(); i++) {
            res[i] = a[i] + (i ? res[i - 1] : 0);
            if (i)
                res[i] = max(res[i], a[i - 1] - a[i] + (i >= 2 ? res[i - 2] : 0));
        }
        return res.back();
    }
};