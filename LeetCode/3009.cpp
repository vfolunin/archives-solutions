class Solution {
public:
    int maxIntersectionCount(vector<int> &a) {
        map<int, int> deltas;
        for (int i = 0; i + 1 < a.size(); i++) {
            int l = a[i] * 2;
            int r = a[i + 1] * 2;
            
            if (i + 2 < a.size())
                r += a[i] < a[i + 1] ? -1 : 1;

            if (l > r)
                swap(l, r);

            deltas[l]++;
            deltas[r + 1]--;
        }

        int cur = 0, res = 0;
        for (auto &[_, delta] : deltas) {
            cur += delta;
            res = max(res, cur);
        }
        return res;
    }
};