class Solution {
public:
    int maximumGap(string &a, string &b) {
        vector<int> l(a.size());
        for (int ai = 0, bi = 0; ai < a.size() && bi < b.size(); bi++) {
            if (a[ai] == b[bi]) {
                l[ai] = bi;
                ai++;
            }
        }

        vector<int> r(a.size());
        for (int ai = a.size() - 1, bi = b.size() - 1; ai >= 0 && bi >= 0; bi--) {
            if (a[ai] == b[bi]) {
                r[ai] = bi;
                ai--;
            }
        }

        int res = 0;
        for (int i = 0; i + 1 < a.size(); i++)
            res = max(res, r[i + 1] - l[i]);
        return res;
    }
};