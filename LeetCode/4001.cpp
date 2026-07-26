class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>> &a, vector<vector<int>> &b) {
        vector<vector<int>> res;
        for (int ai = 0, bi = 0; ai < a.size() || bi < b.size(); ) {
            int time = 1e9, value = 0;
            if (ai < a.size()) {
                time = min(time, a[ai][0]);
                value += a[ai][1];
            }
            if (bi < b.size()) {
                time = min(time, b[bi][0]);
                value += b[bi][1];
            }
            
            res.push_back({ time, value });

            if (ai < a.size() && a[ai][0] == time)
                ai++;
            if (bi < b.size() && b[bi][0] == time)
                bi++;
        }
        return res;
    }
};