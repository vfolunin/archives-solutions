class Solution {
public:
    vector<bool> isArraySpecial(vector<int> &a, vector<vector<int>> &queries) {
        vector<int> pos;
        for (int i = 0; i + 1 < a.size(); i++)
            if ((a[i] + a[i + 1]) % 2 == 0)
                pos.push_back(i);

        vector<bool> res;
        for (vector<int> &query : queries) {
            auto it = lower_bound(pos.begin(), pos.end(), query[0]);
            res.push_back(it == pos.end() || *it >= query[1]);
        }
        return res;
    }
};