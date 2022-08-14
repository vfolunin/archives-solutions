class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>> &a) {
        vector<vector<int>> res(a.size() - 2, vector<int>(a.size() - 2));
        for (int y = 0; y < res.size(); y++)
            for (int x = 0; x < res.size(); x++)
                for (int dy = 0; dy < 3; dy++)
                    for (int dx = 0; dx < 3; dx++)
                        res[y][x] = max(res[y][x], a[y + dy][x + dx]);
        return res;
    }
};