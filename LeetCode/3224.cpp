class Solution {
public:
    int minChanges(vector<int> &a, int limit) {
        unordered_map<int, int> diffCount;
        vector<int> maxDiffs;
        for (int l = 0, r = a.size() - 1; l < r; l++, r--) {
            diffCount[abs(a[l] - a[r])]++;
            maxDiffs.push_back(max({ a[l], a[r], limit - a[l], limit - a[r] }));
        }
        sort(maxDiffs.begin(), maxDiffs.end());
        
        int res = 1e9;
        for (int diff = 0; diff <= limit; diff++) {
            int pairCountWithPrice2 = lower_bound(maxDiffs.begin(), maxDiffs.end(), diff) - maxDiffs.begin();
            int pairCountWithPrice1 = a.size() / 2 - pairCountWithPrice2 - diffCount[diff];
            res = min(res, pairCountWithPrice2 * 2 + pairCountWithPrice1);
        }
        return res;
    }
};