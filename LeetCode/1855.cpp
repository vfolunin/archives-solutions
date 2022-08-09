class Solution {
public:
    int maxDistance(vector<int> &a, vector<int> &b) {
        int res = 0;
        for (int ai = 0, bi = 0; ai < a.size(); ai++) {
            while (bi + 1 < b.size() && a[ai] <= b[bi + 1])
                bi++;
            res = max(res, bi - ai);
        }
        return res;
    }
};