class Solution {
public:
    vector<long long> findMaxSum(vector<int> &a, vector<int> &b, int limit) {
        vector<int> order(a.size());
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int lhs, int rhs) {
            return a[lhs] < a[rhs];
        });

        long long valueSum = 0;
        multiset<int> values;
        vector<long long> res(a.size());

        for (int i = 0; i < order.size(); i++) {
            if (i && a[order[i - 1]] == a[order[i]])
                res[order[i]] = res[order[i - 1]];
            else
                res[order[i]] = valueSum;

            valueSum += b[order[i]];
            values.insert(b[order[i]]);
            if (values.size() > limit) {
                valueSum -= *values.begin();
                values.erase(values.begin());
            }
        }

        return res;
    }
};