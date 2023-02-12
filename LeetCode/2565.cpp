class Solution {
public:
    int minimumScore(string &a, string &b) {
        vector<int> l = { -1 };
        for (int ai = 0, bi = 0; ai < a.size() && bi < b.size(); ai++) {
            if (a[ai] == b[bi]) {
                l.push_back(ai);
                bi++;
            }
        }
        
        vector<int> r;
        for (int ai = a.size() - 1, bi = b.size() - 1; ai >= 0 && bi >= 0; ai--) {
            if (a[ai] == b[bi]) {
                r.push_back(ai);
                bi--;
            }
        }
        reverse(r.begin(), r.end());
        r.push_back(a.size());

        int res = b.size();
        for (int li = 0, ri = 0; li < l.size(); li++) {
            while (l[li] >= r[ri])
                ri++;
            res = min(res, (int)b.size() - (li + (int)r.size() - 1 - ri));
        }
        return max(res, 0);
    }
};