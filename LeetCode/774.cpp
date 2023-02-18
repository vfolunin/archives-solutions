class Solution {
    bool can(vector<int> &a, int k, double dist) {
        for (int i = 1; i < a.size(); i++)
            k -= int((a[i] - a[i - 1]) / dist);
        return k >= 0;
    }

public:
    double minmaxGasDist(vector<int> &a, int k) {
        double l = 0, r = 1e9;
        for (int i = 0; i < 100; i++) {
            double m = (l + r) / 2;
            if (can(a, k, m))
                r = m;
            else
                l = m;
        }
        return l;
    }
};