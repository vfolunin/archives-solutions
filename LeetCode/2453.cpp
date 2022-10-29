class Solution {
public:
    int destroyTargets(vector<int> &a, int mod) {
        unordered_map<int, int> count;
        int maxCount = 0;
        for (int value : a)
            maxCount = max(maxCount, ++count[value % mod]);
        
        int res = 1e9;
        for (int value : a)
            if (count[value % mod] == maxCount)
                res = min(res, value);
        return res;
    }
};