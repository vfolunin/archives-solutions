class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>> &a, vector<vector<int>> &b) {
        vector<vector<int>> res(a.size(), vector<int>(b[0].size()));
        for (int y = 0; y < a.size(); y++)
            for (int x = 0; x < b[0].size(); x++)
                for (int i = 0; i < a[0].size(); i++)
                    res[y][x] += a[y][i] * b[i][x];
        return res;
    }
};