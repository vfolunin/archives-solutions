class Solution {
public:
    vector<int> minDifference(vector<int> &a, vector<vector<int>> &queries) {
        vector<vector<int>> pos(100);
        for (int i = 0; i < a.size(); i++)
            pos[a[i] - 1].push_back(i);
        
        vector<int> res(queries.size(), -1);
        
        for (int i = 0; i < queries.size(); i++) {
            int &l = queries[i][0], &r = queries[i][1], last = -1;
            for (int value = 0; value < pos.size(); value++) {
                auto it = lower_bound(pos[value].begin(), pos[value].end(), l);
                if (it != pos[value].end() && *it <= r) {
                    if (last != -1 && (res[i] == -1 || res[i] > value - last))
                        res[i] = value - last;
                    last = value;
                }
            }
        }
        
        return res;
    }
};