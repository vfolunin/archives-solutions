class Solution {
public:
    int findShortestSubArray(vector<int> &a) {
        unordered_map<int, int> l, r, count;
        int maxCount = 0;
        
        for (int i = 0; i < a.size(); i++) {
            if (!l.count(a[i]))
                l[a[i]] = i;
            r[a[i]] = i;
            maxCount = max(maxCount, ++count[a[i]]);
        }
        
        int res = a.size();
        for (auto &[value, count] : count)
            if (count == maxCount)
                res = min(res, r[value] - l[value] + 1);
        return res;
    }
};