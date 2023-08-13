class Solution {
public:
    int minAbsoluteDifference(vector<int> &a, int dist) {
        set<int> values;
        int res = 2e9;
        
        for (int i = dist; i < a.size(); i++) {
            values.insert(a[i - dist]);

            auto it = values.lower_bound(a[i]);
            if (it != values.end())
                res = min(res, *it - a[i]);
            if (it != values.begin())
                res = min(res, a[i] - *prev(it));
        }
        
        return res;
    }
};