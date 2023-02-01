class Solution {
public:
    vector<int> arraysIntersection(vector<int> &a, vector<int> &b, vector<int> &c) {
        vector<int> res;

        for (int ai = 0, bi = 0, ci = 0; ai < a.size() && bi < b.size() && ci < c.size(); ) {
            if (a[ai] == b[bi] && a[ai] == c[ci]) {
                res.push_back(a[ai]);
                ai++;
                bi++;
                ci++;
            } else if (a[ai] <= b[bi] && a[ai] <= c[ci]) {
                ai++;
            } else if (b[bi] <= a[ai] && b[bi] <= c[ci]) {
                bi++;
            } else {
                ci++;
            }
        }

        return res;
    }
};