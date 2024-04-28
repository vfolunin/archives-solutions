class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>> &a) {
        int h = a.size(), w = a[0].size();

        vector<vector<int>> u(h, vector<int>(w));
        vector<vector<int>> l(h, vector<int>(w));
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                u[y][x] = a[y][x] + (y ? u[y - 1][x] : 0);
                l[y][x] = a[y][x] + (x ? l[y][x - 1] : 0);
            }
        }

        vector<vector<int>> d(h, vector<int>(w));
        vector<vector<int>> r(h, vector<int>(w));
        for (int y = h - 1; y >= 0; y--) {
            for (int x = w - 1; x >= 0; x--) {
                d[y][x] = a[y][x] + (y + 1 < h ? d[y + 1][x] : 0);
                r[y][x] = a[y][x] + (x + 1 < w ? r[y][x + 1] : 0);
            }
        }

        long long res = 0;
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                if (a[y][x]) {
                    res += (u[y][x] - 1LL) * (r[y][x] - 1LL);
                    res += (u[y][x] - 1LL) * (l[y][x] - 1LL);
                    res += (r[y][x] - 1LL) * (d[y][x] - 1LL);
                    res += (d[y][x] - 1LL) * (l[y][x] - 1LL);
                }
            }
        }
        return res;
    }
};