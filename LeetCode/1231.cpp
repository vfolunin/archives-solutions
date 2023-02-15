class Solution {
    bool can(vector<int> &a, int k, int sum) {
        int parts = 0, partSum = 0;
        for (int value : a) {
            partSum += value;
            if (partSum >= sum) {
                parts++;
                partSum = 0;
            }
        }
        return parts > k;
    }

public:
    int maximizeSweetness(vector<int> &a, int k) {
        int l = 0, r = 2e9;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (can(a, k, m))
                l = m;
            else
                r = m;
        }
        return l;
    }
};