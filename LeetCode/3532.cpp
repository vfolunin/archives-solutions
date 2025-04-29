class Solution {
public:
    vector<bool> pathExistenceQueries(int vertexCount, vector<int> &a, int limit, vector<vector<int>> &queries) {
        vector<int> order(vertexCount);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int lhs, int rhs) {
            return a[lhs] < a[rhs];
        });

        vector<int> pos(vertexCount);
        for (int i = 0; i < vertexCount; i++)
            pos[order[i]] = i;
        
        vector<int> gap;
        for (int i = 0; i + 1 < vertexCount; i++)
            if (a[order[i + 1]] - a[order[i]] > limit)
                gap.push_back(i);
        
        vector<bool> res(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            int l = order[queries[i][0]];
            int r = order[queries[i][1]];
            if (l > r)
                swap(l, r);
            
            auto lIt = lower_bound(gap.begin(), gap.end(), l);
            auto rIt = lower_bound(gap.begin(), gap.end(), r);
            res[i] = lIt == rIt;
        }
        return res;
    }
};