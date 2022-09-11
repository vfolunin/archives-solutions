class Solution {
public:
    vector<int> avoidFlood(vector<int> &rains) {
        set<int> freeDays;
        unordered_map<int, int> nextRainDay;
        vector<int> res(rains.size(), -1);
        
        for (int i = rains.size() - 1; i >= 0; i--) {
            if (!rains[i]) {
                freeDays.insert(i);
                res[i] = 1;
            } else {
                if (nextRainDay.count(rains[i])) {
                    auto it = freeDays.lower_bound(nextRainDay[rains[i]]);
                    if (it == freeDays.begin())
                        return {};
                    res[*prev(it)] = rains[i];
                    freeDays.erase(prev(it));
                }
                nextRainDay[rains[i]] = i;
            }
        }
        
        return res;
    }
};