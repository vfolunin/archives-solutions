class Solution {
public:
    int jobScheduling(vector<int> &l, vector<int> &r, vector<int> &bonus) {
        vector<int> order(l.size());
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int a, int b) {
            return r[a] < r[b];
        });

        map<int, int> totalBonus = { { 0, 0 } };
        int res = 0;

        for (int i : order) {
            totalBonus[r[i]] = max(
                prev(totalBonus.upper_bound(r[i]))->second,
                prev(totalBonus.upper_bound(l[i]))->second + bonus[i]
            );
            res = max(res, totalBonus[r[i]]);
        }

        return res;
    }
};
