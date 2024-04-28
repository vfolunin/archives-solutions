class Solution {
public:
    int minimumOperations(vector<vector<int>> &a) {
        int h = a.size(), w = a[0].size();

        vector<vector<int>> count(w, vector<int>(10));
        for (int y = 0; y < h; y++)
            for (int x = 0; x < w; x++)
                count[x][a[y][x]]++;

        vector<vector<int>> res(w, vector<int>(10, 1e9));
        for (int value = 0; value < 10; value++)
            res[0][value] = h - count[0][value];

        for (int x = 1; x < w; x++)
            for (int value = 0; value < 10; value++)
                for (int prevValue = 0; prevValue < 10; prevValue++)
                    if (value != prevValue)
                        res[x][value] = min(res[x][value], res[x - 1][prevValue] + h - count[x][value]);

        return *min_element(res.back().begin(), res.back().end());
    }
};