class Solution {
public:
    int minimumDeviation(vector<int> &a) {
        vector<pair<int, int>> pairs(a.size());  
        for (int i = 0; i < a.size(); i++) {
            pairs[i] = { a[i], a[i] };
            while (pairs[i].first % 2 == 0)
                pairs[i].first /= 2;
            if (pairs[i].second % 2)
                pairs[i].second *= 2;
        }
        
        set<pair<int, int>> pairSet(pairs.begin(), pairs.end());
        int res = prev(pairSet.end())->first - pairSet.begin()->first;
        
        while (pairSet.begin()->first < pairSet.begin()->second) {
            auto [value, limit] = *pairSet.begin();
            pairSet.erase(pairSet.begin());
            pairSet.insert({ value * 2, limit });
            res = min(res, prev(pairSet.end())->first - pairSet.begin()->first);
        }
        
        return res;
    }
};