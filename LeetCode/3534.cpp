class Solution {
public:
    vector<int> pathExistenceQueries(int vertexCount, vector<int> &a, int limit, vector<vector<int>> &queries) {
        vector<int> order(vertexCount);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int l, int r) {
            return a[l] < a[r];
        });

        vector<int> pos(order.size());
        for (int i = 0; i < order.size(); i++)
            pos[order[i]] = i;

        vector<vector<int>> to(20, vector<int>(order.size()));
        for (int l = 0, r = 0; l < order.size(); l++) {
            while (r + 1 < order.size() && a[order[l]] + limit >= a[order[r + 1]])
                r++;
            to[0][l] = r;
        }
        for (int level = 1; level < to.size(); level++)
            for (int v = 0; v < to[level].size(); v++)
                to[level][v] = to[level - 1][to[level - 1][v]];
        
        vector<int> res(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            int a = pos[queries[i][0]], b = pos[queries[i][1]];
            if (a > b)
                swap(a, b);
            if (to.back()[a] < b) {
                res[i] = -1;
                continue;
            }
            
            res[i] = a != b;
            for (int level = to.size() - 1; level >= 0; level--) {
                if (to[level][a] < b) {
                    a = to[level][a];
                    res[i] += 1 << level;
                }
            }
        }
        return res;
    }
};