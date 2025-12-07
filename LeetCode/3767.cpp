class Solution {
public:
    long long maxPoints(vector<int> &a, vector<int> &b, int aCount) {
        vector<int> order(a.size());
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int l, int r) {
            return a[l] - b[l] > a[r] - b[r];
        });

        long long res = 0;
        for (int i = 0; i < aCount; i++)
            res += a[order[i]];
        for (int i = aCount; i < a.size(); i++)
            res += max(a[order[i]], b[order[i]]);
        return res;
    }
};