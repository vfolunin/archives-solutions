class Solution {
    bool can(vector<int> &a, int amount, int storeLimit) {
        int storeCount = 0;
        for (int value : a)
            storeCount += (value + amount - 1) / amount;
        return storeCount <= storeLimit;
    }
    
public:
    int minimizedMaximum(int storeLimit, vector<int> &a) {
        int l = 0, r = 1e5;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (can(a, m, storeLimit))
                r = m;
            else
                l = m;
        }
        return r;
    }
};