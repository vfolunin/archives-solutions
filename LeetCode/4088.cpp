class Solution {
public:
    int peakValleyDifference(vector<int> &a) {
        int res = 0;
        for (int i = 1; i + 1 < a.size(); i++) {
            if (a[i - 1] < a[i] && a[i] > a[i + 1])
                res += a[i];
            else if (a[i - 1] > a[i] && a[i] < a[i + 1])
                res -= a[i];
        }
        return res;
    }
};