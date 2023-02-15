class Solution {
public:
    vector<int> shortestDistanceColor(vector<int> &a, vector<vector<int>> &queries) {
        vector<vector<int>> pos(3, vector<int>(1, -2e9));
        for (int i = 0; i < a.size(); i++)
            pos[a[i] - 1].push_back(i);
        for (vector<int> &p : pos)
            p.push_back(2e9);
        
        vector<int> res(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            vector<int> &p = pos[queries[i][1] - 1];
            auto r = lower_bound(p.begin(), p.end(), queries[i][0]);
            auto l = prev(r);
            res[i] = min(queries[i][0] - *l, *r - queries[i][0]);
            if (res[i] > 1e9)
                res[i] = -1;
        }
        return res;
    }
};