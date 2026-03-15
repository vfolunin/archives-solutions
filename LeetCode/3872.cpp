class Solution {
public:
    int longestArithmetic(vector<int> &a) {
        vector<int> l(a.size(), 1), lDelta(a.size(), -1e9);
        for (int i = 1; i < a.size(); i++) {
            l[i] = 2;
            lDelta[i] = a[i] - a[i - 1];
            if (i >= 2 && lDelta[i] == lDelta[i - 1])
                l[i] = l[i - 1] + 1;
        }

        vector<int> r(a.size(), 1), rDelta(a.size(), -1e9);
        for (int i = (int)a.size() - 2; i >= 0; i--) {
            r[i] = 2;
            rDelta[i] = a[i + 1] - a[i];
            if (i <= a.size() - 3 && rDelta[i] == rDelta[i + 1])
                r[i] = r[i + 1] + 1;
        }

        int res = 1;
        for (int i = 0; i < a.size(); i++) {
            if (i)
                res = max(res, l[i - 1] + 1);
            if (i + 1 < a.size())
                res = max(res, r[i + 1] + 1);
            if (i && i + 1 < a.size() && (a[i + 1] - a[i - 1]) % 2 == 0) {
                int delta = (a[i + 1] - a[i - 1]) / 2;
                res = max(res, (lDelta[i - 1] == delta ? l[i - 1] : 1) + 1 + (rDelta[i + 1] == delta ? r[i + 1] : 1));
            }
        }
        return res;
    }
};