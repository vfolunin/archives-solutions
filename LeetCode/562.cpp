class Solution {
public:
    int longestLine(vector<vector<int>> &a) {
        vector<vector<int>> row = a, col = a, d1 = a, d2 = a;
        int res = 0;

        for (int y = 0; y < a.size(); y++) {
            for (int x = 0; x < a[0].size(); x++) {
                if (!a[y][x])
                    continue;
                
                if (x)
                    row[y][x] = row[y][x - 1] + 1;
                if (y)
                    col[y][x] = col[y - 1][x] + 1;
                if (y && x)
                    d1[y][x] = d1[y - 1][x - 1] + 1;
                if (y && x + 1 < a[0].size())
                    d2[y][x] = d2[y - 1][x + 1] + 1;
                
                res = max({ res, row[y][x], col[y][x], d1[y][x], d2[y][x] });
            }
        }

        return res;
    }
};