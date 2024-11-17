class Solution {
    bool can(vector<int> &a, int value1, int value2, int limit) {
        int last = 0, row = 0;
        for (int value : a) {
            if (value == -1) {
                row++;
            } else {
                if (last && row) {
                    int delta = min(max(abs(last - value1), abs(value1 - value)), max(abs(last - value2), abs(value2 - value)));
                    if (delta > limit && (row == 1 || value1 + limit < value2))
                        return 0;
                }

                last = value;
                row = 0;
            }
        }
        return 1;
    }

public:
    int minDifference(vector<int> &a) {
        int minValue = 2e9, maxValue = 0, l = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] == -1)
                continue;
            
            if (i && a[i - 1] == -1 || i + 1 < a.size() && a[i + 1] == -1) {
                minValue = min(minValue, a[i]);
                maxValue = max(maxValue, a[i]);
            }

            if (i + 1 < a.size() && a[i + 1] != -1)
                l = max(l, abs(a[i] - a[i + 1]));
        }
        l--;

        int r = max(l + 1, (maxValue - minValue + 1) / 2);
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (can(a, minValue + m, maxValue - m, m))
                r = m;
            else
                l = m;
        }
        return r;
    }
};