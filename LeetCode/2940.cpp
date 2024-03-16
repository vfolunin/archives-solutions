class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int> &a, vector<vector<int>> &queries) {
        for (vector<int> &query : queries)
            if (query[0] > query[1])
                swap(query[0], query[1]);
        
        vector<int> order(queries.size());
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int lhs, int rhs) {
            return queries[lhs][1] > queries[rhs][1];
        });

        vector<int> res(queries.size()), stack;
        int ar = a.size() - 1;

        for (int i : order) {
            int ql = queries[i][0], qr = queries[i][1];

            if (ql == qr || a[ql] < a[qr]) {
                res[i] = qr;
                continue;
            }

            for ( ; ar > qr; ar--) {
                while (!stack.empty() && a[ar] >= a[stack.back()])
                    stack.pop_back();
                stack.push_back(ar);
            }

            auto it = upper_bound(stack.rbegin(), stack.rend(), ql, [&](int lhs, int rhs) {
                return a[lhs] < a[rhs];
            });
            res[i] = it != stack.rend() ? *it : -1;
        }

        return res;
    }
};