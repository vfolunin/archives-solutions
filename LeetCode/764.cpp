class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>> &freeCells) {
        vector<vector<int>> a(n, vector<int>(n, 1));
        for (vector<int> &freeCell : freeCells)
            a[freeCell[0]][freeCell[1]] = 0;
        
        vector<vector<int>> u(n, vector<int>(n));
        vector<vector<int>> l(n, vector<int>(n));
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < n; x++) {
                if (a[y][x]) {
                    u[y][x] = 1 + (y ? u[y - 1][x] : 0);
                    l[y][x] = 1 + (x ? l[y][x - 1] : 0);
                }
            }
        }
        
        vector<vector<int>> d(n, vector<int>(n));
        vector<vector<int>> r(n, vector<int>(n));
        for (int y = n - 1; y >= 0; y--) {
            for (int x = n - 1; x >= 0; x--) {
                if (a[y][x]) {
                    d[y][x] = 1 + (y + 1 < n ? d[y + 1][x] : 0);
                    r[y][x] = 1 + (x + 1 < n ? r[y][x + 1] : 0);
                }
            }
        }
        
        int res = 0;
        for (int y = 0; y < n; y++)
            for (int x = 0; x < n; x++)
                res = max(res, min({ u[y][x], l[y][x], r[y][x], d[y][x] }));
        return res;
    }
};