class Solution {
public:
    int findMaxVal(int size, vector<vector<int>> &limits, vector<int> &diffLimit) {
        vector<int> valueLimit(size, 1e9);
        for (vector<int> &limit : limits)
            valueLimit[limit[0]] = limit[1];
        valueLimit[0] = 0;
        
        vector<int> l = valueLimit;
        for (int i = 1; i < l.size(); i++)
            l[i] = min(l[i], l[i - 1] + diffLimit[i - 1]);
        
        vector<int> r = valueLimit;
        for (int i = (int)r.size() - 2; i >= 0; i--)
            r[i] = min(r[i], r[i + 1] + diffLimit[i]);
        
        int res = 0;
        for (int i = 0; i < l.size(); i++)
            res = max(res, min(l[i], r[i]));
        return res;
    }
};