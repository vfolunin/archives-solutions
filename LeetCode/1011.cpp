class Solution {
    bool can(vector<int> &a, int dayLimit, int sumLimit) {
        int sum = 0, days = 1;
        for (int value : a) {
            if (sum + value <= sumLimit) {
                sum += value;
            } else {
                sum = value;
                days++;
            }
        }
        return days <= dayLimit;
    }
    
public:
    int shipWithinDays(vector<int> &a, int dayLimit) {
        int l = *max_element(a.begin(), a.end()) - 1, r = 1e9;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (can(a, dayLimit, m))
                r = m;
            else
                l = m;
        }
        return r;
    }
};