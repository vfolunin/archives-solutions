class Solution {
    bool can(vector<int> &a, int limit) {
        long long free = 0;
        for (int value : a) {
            if (value > limit) {
                free -= value - limit;
                if (free < 0)
                    return 0;
            } else {
                free += limit - value;
            }
        }
        return 1;
    }
    
public:
    int minimizeArrayValue(vector<int> &a) {
        int l = -1, r = 2e9;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (can(a, m))
                r = m;
            else
                l = m;
        }
        return r;
    }
};