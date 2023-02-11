class Solution {
    bool can(vector<int> &a, int p, double level) {
        double have = 0, need = 0;
        for (int value : a) {
            if (value >= level)
                have += value - level;
            else
                need += level - value;
        }
        return have * (100.0 - p) / 100 >= need;
    }

public:
    double equalizeWater(vector<int> &a, int p) {
        double l = 0, r = 1e9;
        for (int i = 0; i < 100; i++) {
            double m = (l + r) / 2;
            if (can(a, p, m))
                l = m;
            else
                r = m;
        }
        return l;
    }
};