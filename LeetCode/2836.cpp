class Solution {
public:
    long long getMaxFunctionValue(vector<int> &receiver, long long mask) {
        vector<vector<int>> to(40, vector<int>(receiver.size()));
        vector<vector<long long>> sum(40, vector<long long>(receiver.size()));

        for (int v = 0; v < receiver.size(); v++)
            to[0][v] = sum[0][v] = receiver[v];

        for (int bit = 1; bit < to.size(); bit++) {
            for (int v = 0; v < receiver.size(); v++) {
                to[bit][v] = to[bit - 1][to[bit - 1][v]];
                sum[bit][v] = sum[bit - 1][v] + sum[bit - 1][to[bit - 1][v]];
            }
        }

        long long res = 0;

        for (int i = 0; i < receiver.size(); i++) {
            long long cur = i;
            int v = i;

            for (int bit = to.size() - 1; bit >= 0; bit--) {
                if (mask & (1LL << bit)) {
                    cur += sum[bit][v];
                    v = to[bit][v];
                }
            }

            res = max(res, cur);
        }

        return res;
    }
};