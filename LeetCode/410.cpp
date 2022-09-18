class Solution {
    bool can(vector<int> &a, int partLimit, int sumLimit) {
        int parts = 1, sum = 0;
        for (int value : a) {
            if (sum + value <= sumLimit) {
                sum += value;
            } else {
                sum = value;
                parts++;
            }
        }
        return parts <= partLimit;
    }
    
public:
    int splitArray(vector<int> &a, int parts) {
        int l = *max_element(a.begin(), a.end()) - 1, r = 1e9;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (can(a, parts, m))
                r = m;
            else
                l = m;
        }
        return r;
    }
};